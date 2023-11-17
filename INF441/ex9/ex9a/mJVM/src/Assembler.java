

/**
 * 
 * Tradu��o de assembly da m�quina virtual MicroJava
 * para c�digo bin�rio da mesma m�quina.
 * 
 * Uso:
 *   java Assembler arquivoFonte arquivoObjeto
 *   
 * Al�m das instru��es definidas no documento de
 * especifica��o da m�quina virtual MicroJava, o
 * assembly processado por este programa aceita:
 * 
 * - coment�rios em linhas come�ando com "#";
 * 
 * - instru��o "data numVars", onde "numVars" � um
 * n�mero inteiro positivo, para definir o tamanho
 * da �rea de dados globais (est�ticos);
 * 
 * - instru��o "label nomeLabel", para defini��o
 * e refer�ncia de pontos no c�digo;
 * 
 * - uso de r�tulos (labels) definidos em instru��es
 * como "call", desvios condicionais e incondicionais.
 *   
 */

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.RandomAccessFile;
import java.util.ArrayList;
import java.util.Collection;
import java.util.HashMap;
import java.util.Iterator;

class Label {
	private short posicao;
	private ArrayList ocorrencias;
	public Label() {
		posicao = -1;
		ocorrencias = new ArrayList();
	}
	public short getPosicao() {
		return posicao;
	}
	public int getNumOcorrencias() {
		return ocorrencias.size();
	}
	public short getOcorrencia(int i) {
		return ((Short) ocorrencias.get(i)).shortValue();
	}
	public void setPosicao(short i) {
		posicao = i;
	}
	public void addOcorrencia(short i) {
		ocorrencias.add(new Short(i));
	}
}

class LabelList {
	private HashMap lista;
	public LabelList() {
		lista = new HashMap();
	}
	void addOcorrencia(String labelName, short i) {
		Label lab = (Label) lista.get(labelName);
		if (lab == null) {
			lab = new Label();
			lista.put(labelName, lab);
		}
		lab.addOcorrencia(i);
	}
	void setPosicao(String labelName, short i) {
		Label lab = (Label) lista.get(labelName);
		if (lab == null) {
			lab = new Label();
			lista.put(labelName, lab);
		}
		lab.setPosicao(i);
	}
	public Label getLabel(String labelName) {
		return (Label) lista.get(labelName);
	}
	public Collection getList() {
		return lista.values();
	}
}


public class Assembler {

	  private static final int				// instruction codes
		load        =  1,
		load0       =  2,
		load1       =  3,
		load2       =  4,
		load3       =  5,
		store       =  6,
		store0      =  7,
		store1      =  8,
		store2      =  9,
		store3      = 10,
		getstatic   = 11,
		putstatic   = 12,
		getfield    = 13,
		putfield    = 14,
		const0      = 15,
		const1      = 16,
		const2      = 17,
		const3      = 18,
		const4      = 19,
		const5      = 20,
		const_m1    = 21,
		const_      = 22,
		add         = 23,
		sub         = 24,
		mul         = 25,
		div         = 26,
		rem         = 27,
		neg         = 28,
		shl         = 29,
		shr         = 30,
		new_        = 31,
		newarray    = 32,
		aload       = 33,
		astore      = 34,
		baload      = 35,
		bastore     = 36,
		arraylength = 37,
		pop         = 38,
		jmp         = 39,
		jeq         = 40,
		jne         = 41,
		jlt         = 42,
		jle         = 43,
		jgt         = 44,
		jge         = 45,
		call        = 46,
		return_     = 47,
		enter       = 48,
		exit        = 49,
		read        = 50,
		print       = 51,
		bread       = 52,
		bprint      = 53,
		trap		= 54,
				
		constF		= 55,
		
		addF		= 56,
		subF		= 57,
		mulF		= 58,
		divF		= 59,
		negF		= 60,
		
		jeqF		= 61,
		jneF		= 62,
		jltF		= 63,
		jleF		= 64,
		jgtF		= 65,
		jgeF		= 66,
		
		readF		= 67,
		printF		= 68,
		
		iToF		= 69,
		fToI		= 70
;

	private static String[] opcode = {
			"???","load","load0","load1","load2",
			"load3","store","store0","store1","store2",
			"store3","getstatic","putstatic","getfield","putfield",
			"const0","const1","const2","const3","const4",
			"const5","constm1","const","add","sub",
			"mul","div","rem","neg","shl",
			"shr","new","newarray","aload","astore",
			"baload","bastore","arraylen","pop","jmp",
			"jeq","jne","jlt","jle","jgt",
			"jge","call","return","enter","exit",
			"read","print","bread","bprint","trap",
			"constF","addF","subF","mulF","divF",
			"negF",
			"jeqF","jneF","jltF","jleF","jgtF","jgeF",
			"readF","printF", "itof", "ftoi"
		};
	
	private int findCommandCode(String s) {
		int j = 0;
		while (j < opcode.length && s.compareToIgnoreCase(opcode[j]) != 0) {
			++j;
		}
		if (j >= opcode.length) {
			return -1;
		}
		return j;
	}

	private static final int TAM_CABECALHO = 14;
	
	private String outFileName;
	
	private BufferedReader inFile;
	private RandomAccessFile outFile;
	
	private LabelList labelList;

	
	public Assembler(String infileName, String outFileName) {
		this.outFileName = outFileName;
		labelList = new LabelList();
		try {
			inFile = new BufferedReader(new FileReader(infileName));
			outFile = new RandomAccessFile(new File(outFileName), "rw");
		} catch (FileNotFoundException e) {
			System.out.println("Arquivo nao encontrado: " + infileName);
			return;
		}	
	}
	
	
	public boolean assemble() {
		String line;
		try {
			int tamMemoria = 0;
			int tamCodigo = 0;
			outFile.writeBytes("MJ");
			for (int i = 0; i < 12; ++i) {
				outFile.writeByte(0);
			}
			while (true) {
				line = inFile.readLine();
				if (line == null) {
					break;
				}
				line = line.trim();
				if (line.compareTo("") == 0 || line.charAt(0) == '#') {
					continue;
				}
				int i = 0;
				while (i < line.length()
						&& Character.isLetterOrDigit(line.charAt(i))) {
					++i;
				}
				String comando = line.substring(0, i);
								
				String impr = tamCodigo + " " +
						line;
						//comando;
/*				if (comando.equalsIgnoreCase("label") || comando.charAt(0) == 'j') {
					impr += " " + line.substring(i+1);
				}*/
				System.out.println(impr);
				
				if (comando.compareToIgnoreCase("label") == 0) {
					while (i < line.length()
							&& !Character.isLetterOrDigit(line.charAt(i))) {
						++i;
					}
					line = line.substring(i);
					line = line.trim();
					labelList.setPosicao(line, (short) tamCodigo);
					continue;
				}
				
				if (comando.compareToIgnoreCase("data") == 0) {
					while (i < line.length()
							&& !Character.isLetterOrDigit(line.charAt(i))) {
						++i;
					}
					line = line.substring(i);
					line = line.trim();
					int d;
					try {
						d = Integer.parseInt(line);
					} catch (NumberFormatException e) {
						System.out.println("Erro em formato de inteiro no comando: " + comando);
						return false;
					}
					tamMemoria = d;
					continue;
				}
				
				int j = findCommandCode(comando);
				
				if (j == -1) {
					System.out.println("Comando desconhecido: " + comando);
					return false;
				}

				outFile.writeByte(j);
				++tamCodigo;
				while (i < line.length()
						&& !Character.isLetterOrDigit(line.charAt(i))
						&& line.charAt(i) != '-') {
					++i;
				}
				line = line.substring(i);
				i = 0;
				switch (j) {
				case load:
				case store:
				case newarray:
				case enter:
				case trap:
					while (i < line.length() &&
						(Character.isDigit(line.charAt(i))
								|| line.charAt(i) == '-')) {
						++i;
					}
					String strByte = line.substring(0, i);
					byte b1;
					try {
						b1 = Byte.parseByte(strByte);
					} catch (NumberFormatException e) {
						System.out.println("Erro em formato de byte no comando: " + comando);
						return false;
					}
					outFile.writeByte(b1);
					++tamCodigo;
					if (j == 48) {
						while (i < line.length()
								&& !Character.isDigit(line.charAt(i))
								&& line.charAt(i) != '-') {
							++i;
						}
						line = line.substring(i);
						i = 0;
						while (i < line.length() &&
							(Character.isDigit(line.charAt(i))
									|| line.charAt(i) == '-')) {
							++i;
						}
						strByte = line.substring(0, i);
						try {
							b1 = Byte.parseByte(strByte);
						} catch (NumberFormatException e) {
							System.out.println("Erro em formato de byte no comando: " + comando);
							return false;
						}
						outFile.writeByte(b1);
						++tamCodigo;
					}
					break;
				case getstatic:
				case putstatic:
				case getfield:
				case putfield:
				case new_:
					while (i < line.length() &&
						(Character.isDigit(line.charAt(i))
								|| line.charAt(i) == '-')) {
						++i;
					}
					String strShort = line.substring(0, i);
					short short1;
					try {
						short1 = Short.parseShort(strShort);
					} catch (NumberFormatException e) {
						System.out.println("Erro em formato de short no comando: " + comando);
						return false;
					}
					outFile.writeShort(short1);
					tamCodigo += 2;
					break;
				case jmp:
				case jeq:
				case jne:
				case jlt:
				case jle:
				case jgt:
				case jge:
				case call:
				case jeqF:
				case jneF:
				case jgtF:
				case jgeF:
				case jltF:
				case jleF:
					while (i < line.length() &&
						(Character.isLetterOrDigit(line.charAt(i))
						|| line.charAt(i) == '_')) {
						++i;
					}
					String strLabel = line.substring(0, i);
					strLabel = strLabel.trim();
					labelList.addOcorrencia(strLabel, (short) tamCodigo);
					outFile.writeShort(0);
					tamCodigo += 2;
					break;
				case const_:
					while (i < line.length() &&
						(Character.isDigit(line.charAt(i))
								|| line.charAt(i) == '-')) {
						++i;
					}
					String strInt = line.substring(0, i);
					int int1;
					try {
						int1 = Integer.parseInt(strInt);
					} catch (NumberFormatException e) {
						System.out.println("Erro em formato de inteiro no comando: " + comando);
						return false;
					}
					outFile.writeInt(int1);
					tamCodigo += 4;
					break;
				case constF:
					while (i < line.length() &&
						(Character.isDigit(line.charAt(i))
								|| line.charAt(i) == '-'
								|| line.charAt(i) == '.')) {
						++i;
					}
					String strF = line.substring(0, i);
					float f1;
					try {
						f1 = Float.parseFloat(strF);
					} catch (NumberFormatException e) {
						System.out.println("Erro em formato de float no comando: " + comando);
						return false;
					}
					outFile.writeFloat(f1);
					tamCodigo += 4;
					break;
				}
			}
			inFile.close();
			outFile.seek(2);
			outFile.writeInt(tamCodigo);
			outFile.writeInt(tamMemoria);
			int inicCodigo = 0;
			/*
			Label labelMain = labelList.getLabel("main");
			if (labelMain != null) {
				inicCodigo = labelMain.getPosicao();
			}*/
			outFile.writeInt(inicCodigo);
			
			Collection labels = labelList.getList();
			Iterator it = labels.iterator();
			System.out.println("\nlabels:");
			while (it.hasNext()) {
				Label lab = (Label) it.next();
				short posicao = lab.getPosicao();
				System.out.print(posicao + ": ");
				int numOc = lab.getNumOcorrencias();
				for (int k = 0; k < numOc; ++k) {
					short oc = lab.getOcorrencia(k);
					System.out.print(oc + " ");
					outFile.seek(TAM_CABECALHO + oc);
					outFile.writeShort(posicao);
				}
				System.out.println();
			}
			
			outFile.close();
			
			System.out.println("\nArquivo objeto gerado com sucesso em "
					+ outFileName);
			return true;
			
		} catch (IOException e) {
			System.out.println("Erro de leitura");
			return false;
		}

	}
	
	
	public static void main(String [] args) {
		if (args.length != 2) {
			System.out.println("Syntax: java Assembler sourceFile objectFile");
			return;
		}
		String source = args[0], obj = args[1];
		Assembler asm = new Assembler(source, obj);
		asm.assemble();
	}
	
}
