
import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.tree.TerminalNode;

import semantic.interfaces.*;

public class SemanticListener extends MicroJavaBaseListener {

	// Tabela de s�mbolos utilizada durante a an�lise sem�ntica
    private SymbolTable symbolTable;
    
    // Pilha auxiliar para acumular informa��es enquanto navega na �rvore
    private Stack<Object> stack = new Stack<Object>();
    
	// Refer�ncia ao parser, usada para emitir mensagens de erro
	MicroJavaParser parser;

    // F�brica para criar objetos associados a an�lise sem�ntica
    private SemanticFactory semanticFactory;

    // Indica se houve algum erro detectado na an�lise
    private boolean hasErrors = false;

    
    /**
     * Construtor.
     * @param parser
     * @param symbolTable
     * @param semanticFactory
     */
    public SemanticListener(MicroJavaParser parser, SymbolTable symbolTable, SemanticFactory semanticFactory) {
    	this.parser = parser;
    	this.symbolTable = symbolTable;
    	this.semanticFactory = semanticFactory;
    	symbolTable.pushEnvironment();
    }
    
    
    /**
     * Observe que o construtor do listener (acima) j� empilha um ambiente
     * na tabela de s�mbolos, que vai ser associado ao ambiente dos
     * identificadores globais do programa sendo analisado.
     * 
     * Vamos come�ar pela declara��o de vari�veis simples.
     * Observe na gram�tica MicroJava.g4 as regras associadas:
     * 
     *   varDecl : type IDENT (',' IDENT)* ';' ;
     * 
     *   type:
     *       IDENT           # TypeWithoutArray
     *     | IDENT '[' ']'   # TypeWithArray
     *   ;
     *   
     * Vamos redefinir os m�todos que s�o executados ap�s
     * visitar n�s da �rvore constru�dos com as regras acima.
     * Acompanhe os coment�rios e implemente o que � solicitado.
     */

    /**
     * Para tipos simples, o c�digo abaixo j� est� completo.
     * Procura o nome do tipo na tabela e emite msgs de erro, caso necess�rio.
     * Deixa na pilha um objeto denotando o tipo encontrado.
     * Procure entender o c�digo.
     */
    public void exitTypeWithoutArray(MicroJavaParser.TypeWithoutArrayContext ctx) {
    	Token t = ctx.IDENT().getSymbol();
    	String name = t.getText();
    	SemanticSymbol s = symbolTable.getSymbol(name);
    	if (s == null) {
    		emitErrorMessage(t, "Tipo não declarado: " + name);
    		stack.push(symbolTable.getNullType());
    	} else if (!s.isClass()) {
    		emitErrorMessage(t, "Identificador " + name + " não é um tipo válido");
    		stack.push(symbolTable.getNullType());
    	} else {
    		// Empilha o tipo do s�mbolo encontrado, para ser usado em seguida
    		// em outros m�todos do listener.
    		stack.push(s.getSemanticType());
        }
    }

    
    public void exitTypeWithArray(MicroJavaParser.TypeWithArrayContext ctx) {
    	//TODO
    	/**
    	 * Insira c�digo para declarar tipo com array, que � bem semelhante
    	 * a tipo simples. A �nica diferen�a para o m�todo anterior � que,
    	 * no caso de n�o haver nenhum erro, em vez de empilhar o tipo do
    	 * s�mbolo, deve ser empihado um TypeArray com esse tipo dentro dele.
    	 * Trocar:
    	 * 
    	 *     		stack.push(s.getSemanticType());
    	 *     
    	 * pelo empilhamento de um TypeArray com s.getSemanticType() dentro dele.
    	 * Para criar esse tipo, use servi�o adequado da f�brica semanticFactory.
    	 */   
    	Token t = ctx.IDENT().getSymbol();
    	String name = t.getText();
    	SemanticSymbol s = symbolTable.getSymbol(name);
    	if (s == null) {
    		emitErrorMessage(t, "Tipo não declarado: " + name);
    		stack.push(symbolTable.getNullType());
    	} else if (!s.isClass()) {
    		emitErrorMessage(t, "Identificador " + name + " não é um tipo válido");
    		stack.push(symbolTable.getNullType());
    	} else {
    		stack.push(semanticFactory.createTypeArray(s.getSemanticType()));
        }
    }
    
    
    /**
     * O c�digo para declarar vari�veis est� quase completo. Procure entender.
     */
    public void exitVarDecl(MicroJavaParser.VarDeclContext ctx) {
    	/**
    	 * O tipo das var�aveis est� na pilha.
    	 * N�s o empilhamos nos m�todos que acabamos de ver.
    	 * Esse tipo � desempilhado e colocado em st.
    	 */
    	SemanticType st = (SemanticType) stack.pop();
    	/**
    	 * O contexto � consultado usando o m�todo IDENT(), que neste caso
    	 * cont�m uma lista de identificadores que ser�o declarados.
    	 * Por exemplo, em:
    	 *     int x, y, z;
    	 * IDENT() cont�m uma lista com os identificadores x, y, e z.
    	 */
    	for(TerminalNode tn: ctx.IDENT()) { // para cada identificador...
    		/**
    		 * Uma nova vari�vel � inserida na tabela, usando o nome e tipo definidos.
    		 */
    		SymbolVariable s = symbolTable.addSymbolVariable(tn.getText(), st);
    		
    		if(s == null) {
    			emitErrorMessage(tn.getSymbol(),  "Identificador já declarado:" + tn.getText());
    		}
    	}
    }
    /**
     * Execute o programa Piloto e observe o comportamento, usando como entrada o
     * arquivo input/teste01.txt.
     * As impress�es em preto s�o um "debug" da tabela de s�mbolos que pode ser
     * desligado no arquivo Piloto.
     * As impress�es em vermelho s�o erros detectados. Alguns deles poder�o ser
     * corrigidos � medida que formos implementando os outros m�todos da an�lise.
     */
    
    //TODO
    /**
     * Em seguida, fa�a uma altera��o no m�todo acima para emitir
     * msg de erro quando uma vari�vel for declarada 2 vezes com mesmo nome.
     * A msg deve identificar qual vari�vel causa erro, com texto como:
     * 
     *     "Identificador j� declarado: i"
     *     
     * Para isso, basta verificar o valor de s retornado.
     * Os m�todos de inser��o de s�mbolo na tabela retornam null
     * quando n�o conseguem inserir um novo s�mbolo - a causa esperada
     * � que j� exista s�mbolo com esse nome no ambiente atual.
     * Observe que o m�todo de emitir mensagens de erro recebe como
     * primeiro par�metro o token onde o erro ocorreu. Neste caso,
     * use tn.getSymbol().
     * 
     * Execute novamente o Piloto e veja as msgs de erro.
     * Voc� ir� ter mais msgs de erro que o desejado, mas isso �
     * devido ao fato de que ainda n�o estamos controlando o empilhamento
     * de novos ambientes.
     */


    /**
     * Vamos agora analisar declara��es de constantes.
     * As regras da gram�tica s�o:
     * 
     *   constDecl: 'final' type IDENT '=' valConst ';';
     * 
     *   valConst:
     *       INT_NUMBER        # ConstInt
     *     | REAL_NUMBER       # ConstReal
     *     | CHAR_CONST        # ConstStr
     *     ;
     *   
     * Voc� pode encontrar abaixo c�digo pronto para as 3 alternativas
     * da regra valConst.
     */
  
	public void exitConstInt(MicroJavaParser.ConstIntContext ctx) {
		stack.push(symbolTable.getIntegerType());
	}
	
	public void exitConstReal(MicroJavaParser.ConstRealContext ctx) {
		stack.push(symbolTable.getFloatType());		
	}
	
	public void exitConstStr(MicroJavaParser.ConstStrContext ctx) {
		stack.push(symbolTable.getCharType());
	}
	
	
	/**
	 * O c�digo abaixo analisa a declara��o de uma constante.
	 * Complete o c�digo quando solicitado.
	 */
    public void exitConstDecl(MicroJavaParser.ConstDeclContext ctx) {
    	/**
    	 * Pelo menos 2 tipos dever�o estar empilhados em stack,
    	 * e s�o coletados nas vari�veis st2 (tipo do valor da constante) e
    	 * st1 (tipo declarado no programa).
    	 * Por exemplo, em
    	 *     final int size = 10;
    	 * st2 ser� TypeInteger por causa de "10",
    	 * e st1 ser� tamb�m TypeInteger por causa de "int".
    	 */
    	SemanticType st2 = (SemanticType) stack.pop();
    	SemanticType st1 = (SemanticType) stack.pop();
    	/**
    	 * Uma msg de erro � impressa se os tipos n�o forem compat�veis.
    	 */
        if (!compatibleTypes(st1, st2))
        {
            emitErrorMessage(ctx.IDENT().getSymbol(), "Incompatibilidade de tipos");
        } else {
        	//TODO
        	/**
        	 * Insira c�digo para adicionar a constante na tabela de s�mbolos.
        	 * Use o m�todo addSymbolConstant da tabela.
        	 * Use tamb�m
        	 * ctx.IDENT().getText() para obter o nome da constante e
        	 * ctx.valConst().getText() para obter o valor da constante.
        	 * Ap�s a opera��o de adicionar a constante, verifique se ela foi
        	 * realizada com sucesso. Caso contr�rio, emita msg de erro
        	 * indicando identificador repetido.
        	 */        	
        	SymbolConstant s = symbolTable.addSymbolConstant(ctx.IDENT().getText(), st1, ctx.valConst());

            if (s == null) {
                emitErrorMessage(ctx.IDENT().getSymbol(), "Identificador já declarado:" + ctx.IDENT().getText());
            }
        }
    }
	/**
	 * Rode o programa para testar declara��es de constantes.
	 * Insira no arquivo de entrada alguns casos que verifiquem
	 * situa��es de erro, tais como:
	 *     final int size = 10;
	 *     final int size = 20; // repeti��o de declara��o
	 *     final int c = "a"; // incompatibilidade de tipos
	 */

    
    /**
     * A regra da gram�tica associada a declara��o de novas classes �:
     * 
     *   classDecl : 'class' IDENT '{' varDecl* '}' ;
     */

    /**
     * Antes de visitar a declara��o de uma classe, ou seja, antes de processar
     * as declara��es das vari�veis dentro da classe, as a��es abaixo devem
     * ser executadas. Sua tarefa � traduzir os trechos de pseudo-c�digo para Java.
     */
    public void enterClassDecl(MicroJavaParser.ClassDeclContext ctx) {
    	//TODO: traduzir os trechos de pseudo-c�digo, em coment�rio, para Java.
    	Token t = ctx.IDENT().getSymbol();
    	
    	// Adicionar uma classe no ambiente atual da pilha, com nome t.getText()
    	// SymbolClass s = symbolTable.add...
        SymbolClass s = symbolTable.addSymbolClass(t.getText());


    	// Verificar se a adi��o do s�mbolo teve sucesso; se n�o, quer dizer
    	// que o identificador � repetido e uma msg de erro deve ser emitida
        if (s == null) {
            emitErrorMessage(t, "Nome da classe já foi declarado:" + ctx.IDENT().getText());
            stack.push(symbolTable.getNullType());
        } else {
            stack.push(s.getSemanticType());
        }

    	
    	// Empilhar (em stack) o tipo do s�mbolo s que foi adicionado � tabela
		// de s�mbolos, para ser usado no final da declara��o da classe
		// (use s.getSemanticType()).
    	// OBS: o tipo do s�mbolo s� pode ser obtido se s n�o for null;
		// assim, esse c�digo deve ser inserido como "else" do "if" anterior;
		// e para evitar inconsist�ncia, no caso de s for null, empilhe null em stack.
    	
    	// Empilhar um novo ambiente em symbolTable.
    	// Isso ir� fazer com que as vari�veis de varDecl* sejam adicionadas
    	// nesse novo ambiente.    	
        symbolTable.pushEnvironment();

    	
    }
    /**
     * OBS: veja que o c�digo acima menciona 2 pilhas diferentes:
     * - stack � a pilha auxiliar que usamos para compartilhar informa��es entre
     * os m�todos do listener;
     * - a tabela de s�mbolos � por si pr�pria uma pilha de ambientes.
     */

    
    /**
     * Ap�s visitar a declara��o de uma classe, o ambiente constru�do no topo
     * da tabela de s�mbolos cont�m as var��veis internas � classe (atributos).
     * Esse ambiente deve ser desempilhado da tabela de s�mbolos e associado
     * ao tipo do s�mbolo da nova classe (que empilhamos no m�todo anterior).
     * O c�digo abaixo est� completo, basta tirar os coment�rios.
     */
    public void exitClassDecl(MicroJavaParser.ClassDeclContext ctx) {
    	//TODO
    	// Tirar o coment�rio do c�digo.
        Environment e = symbolTable.popEnvironment();
        TypeClass tc = (TypeClass) stack.pop();
        if (tc != null) {
            tc.setEnvironment(e);
        }
    }
    
    /**
     * Ap�s a implementa��o dos 2 m�todos acima, rode novamente o Piloto
     * e veja altera��es no comportamento:
     * - vari�veis internas a declara��es de classe n�o mais conflitam
     * oom vari�veis globais, mesmo se tiverem nomes iguais;
     * - pode-se usar a nova classe como tipo na declara��o de vari�veis.
     */

    
    /**
     * As regras na gram�tica para declara��o de novos m�todos s�o:
     * 
     *     typeOrVoid: type | 'void' ;
     * 
     *     methodDecl : typeOrVoid IDENT '(' formPars ')' varDecl* block ;
     * 
     *     formPars : ( formPar (',' formPar)* )?;
     * 
     *     formPar: type IDENT ;
     * 
     * Passos necess�rios para a an�lise sem�ntica:
     * 
     * 1) Inserir na tabela de s�mbolos um m�todo com tipo de retorno definido
     * por typeOrVoid (tipos dos par�metors ser�o definidos depois).
     * 2) Antes de analisar os par�metros, empilhar novo ambiente na tabela de s�mbolos.
     * 3) Analisar as declara��es dos par�metros como vari�veis locais,
     * que ser�o inseridas no novo ambiente. Al�m disso, inserir os tipos
     * dos par�metros na lista de par�metros do m�todo criado.
     * 4) Continuar o processo, analisando as vari�veis locais do m�todo.
     * 5) Ap�s o t�rmino de toda a an�lise, desempilhar o novo ambiente da tabela
     * de s�mbolos.
     * 
     * Siga as instru��es abaixo para a correta implementa��o da an�lise
     * sem�ntica de declara��es de m�todos.
     */
    

    /**
     * Ao iniciar a decla��o de um m�todo, o token associado ao nome desse
     * m�todo � empilhado, simplesmente para poder ser usado no momento
     * em que for inserida a declara��o na tabela de s�mbolos.
     * O c�digo abaixo est� completo.
     */
    public void enterMethodDecl(MicroJavaParser.MethodDeclContext ctx) {
    	stack.push(ctx.IDENT().getSymbol());
    }

    
    /**
     * O retorno de um m�todo pode ser um tipo qualquer, ou void.
     * O objetivo de ter uma alternativa separada para void � que vari�veis
     * n�o podem ser declaradas com tipo void, somente tipo de retorno
     * de m�todos.
     */
    public void exitTypeOrVoid(MicroJavaParser.TypeOrVoidContext ctx) {
    	//TODO: Traduza o pseudo-c�digo para Java.
    	
    	// Se o tipo n�o for void, n�o h� nada a ser feito, pois ele
    	// j� estar� empilhado em stack.
    	// Mas se o tipo for void, ele deve ser empilhado.
    	// Comece usando ctx.start.getText() para obter o nome do tipo.
    	// Verifique se esse nome � "void" e caso positivo, empilhe em stack
    	// o valor symbolTable.getVoidType().
    	String type = ctx.start.getText();
        if(type == "void"){
            stack.push(symbolTable.getVoidType());
        }
    }

    
    /**
     * O c�digo abaixo est� completo, sendo executado logo antes de
     * se iniciar a an�lise dos par�metros do m�todo.
     * Procure entender.
     */
    public void enterFormPars(MicroJavaParser.FormParsContext ctx) {
    	// Desempilha o tipo de retorno
    	SemanticType returnType = (SemanticType) stack.pop();
    	// Desempilha o nome do m�todo
    	Token methodName = (Token) stack.pop();
    	// Insere uma declara��o de m�todo na tabela de s�mbolos.
    	// O tipo do m�todo � empilhado para depois ser atualizado,
    	// quando se souber quais s�o os tipos dos par�metros.
        SymbolMethod sm = symbolTable.addSymbolMethod(methodName.getText(), returnType);
        if (sm == null) {
        	emitErrorMessage(methodName, "Identificador já declarado: " + methodName.getText());
        	stack.push(null);
        } else {
            stack.push(sm.getSemanticType());
        }
    	// Cria novo ambiente na tabela de s�mbolos
    	symbolTable.pushEnvironment();
    }

    
    /**
     * O c�digo a seguir � executado para cada par�metro da declara��o
     * de um m�todo. Traduza o pseudo-c�digo quando encontrar "TODO".
     */
    public void exitFormPar(MicroJavaParser.FormParContext ctx) {
    	// Desempilha o tipo do par�metro
    	SemanticType st = (SemanticType) stack.pop();
    	// t ser� o Token contendo o nome do par�metro
    	Token t = ctx.IDENT().getSymbol();
    	// No topo da pilha est� o tipo do m�todo sendo declarado.
    	// Ele � obtido sem desempilhar, para ser usado em cada par�metro.
    	TypeMethod mt = (TypeMethod) stack.peek();
        // Inserir o tipo de par�metro na lista de par�metros do m�todo
    	if (mt != null) {
        	mt.getParams().add(st);
    	}
        //TODO:
    	// Inserir a declara��o do par�metro na tabela de s�mbolos,
    	// verificando se n�o h� duplicidade
    	Token m = (Token) stack.pop();
    	SymbolMethod sm = symbolTable.addSymbolMethod(m.getText(), st);
    	
    	if (sm == null) {
            emitErrorMessage(m, "Identificador já declarado: " + m.getText());
            stack.push(null);
        } else {
            stack.push(sm.getSemanticType());
        }
    }

    
    /**
     * Ao terminar de analisar os par�metros, desempilhar
     * o tipo do m�todo que estava em stack.
     */
    public void exitFormPars(MicroJavaParser.FormParsContext ctx) {
    	// Desempilha o tipo do m�todo atual
    	TypeMethod tm = (TypeMethod) stack.pop();
    }
        
    /**
     * Ao terminar a declara��o de um m�todo, o ambiente � desempilhado
     * da tabela de s�mbolos.
     */
    public void exitMethodDecl(MicroJavaParser.MethodDeclContext ctx) {
    	//TODO:
    	// Inserir c�digo para desempilhar o ambiente atual da tabela de s�mbolos.
    	 symbolTable.popEnvironment();
    }
    
    
    /**
     * Insira no arquivo de entrada algumas declara��es de m�todos e rode
     * o programa piloto para testar. Lembre que a declara��o de vari�veis
     * locais � um pouco diferente de Java. Exemplo:
     * 
     *     void main(char p)
     *     int x, k;
     *     {
     *     }
     * 
     * Procure testar situa��es de erro, como par�metros e vari�veis locais
     * com nomes repetidos.
     * 
     * Esta foi a �ltima tarefa deste tutorial.
     * Parab�ns!
     */
    

    
	/**-----------------------------------------------------------------------
	 * As fun��es abaixo j� est�o completamente implementadas e s�o auxiliares
	 * para a implementa��o da an�lise sem�ntica. 
	 *-----------------------------------------------------------------------/
	
    
    /**
     * Verifica se dois tipos s�o compat�veis.
     * @param t1 Primeiro tipo.
     * @param t2 Segundo tipo.
     * @return true se um objeto de tipo t1 pode receber um objeto de tipo t2;
     * false, caso contr�rio.
     */
    private boolean compatibleTypes(SemanticType t1, SemanticType t2) {
    	if (t1.isArray()) {
    		if (t2.isNull()) {
    			return true;
    		}
    		if (!t2.isArray()) {
    			return false;
    		}
    		return compatibleTypes(((TypeArray) t1).getInnerType(), ((TypeArray) t2).getInnerType());
    	}
    	return t1 == t2 || t1.isClass() && t2.isNull();
    }
    
    /**
     * Emite mensagem de erro.
     * @param t Token associado � posi��o do erro.
     * @param msg Mensagem a ser exibida.
     */
    public void emitErrorMessage(Token t, String msg) {
    	hasErrors = true;
    	parser.notifyErrorListeners(t, msg, null);
    }
    
    /**
     * Verifica se algum erro foi detectado.
     * @return true, se houve algum erro; false, caso contr�rio.
     */
    public boolean hasErrors() {
        return hasErrors;
    }

	
}
