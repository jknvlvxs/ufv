import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class AssembleAndRun {

	public static void main(String[] args) throws IOException {
		
		String nomearq, in, out;
		System.out.println("Arquivos mjasm s�o lidos da pasta mjasm...");
		System.out.println("Digite nome do arquivo mjasm (n�o precisa digitar extens�o): ");
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));  
		nomearq = reader.readLine();
		in = "mjasm/" + nomearq + ".mjasm";
		out = "mjobj/" + nomearq + ".mjobj";
		Assembler a = new Assembler(in, out);
		System.out.println();
		System.out.println("--------------------------------");
		System.out.println("Analisando o arquivo assembly...");
		System.out.println("--------------------------------");
		System.out.println();		
		if (a.assemble()) {
			System.out.println();
			System.out.println("--------------------------------");
			System.out.println("Executando o bytecode gerado...");
			System.out.println("--------------------------------");
			System.out.println();		
			MJ.run(out);
		}
	}

}
