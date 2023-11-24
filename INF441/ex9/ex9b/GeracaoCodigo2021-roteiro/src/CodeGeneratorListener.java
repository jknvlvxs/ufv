import java.io.PrintStream;
import java.util.List;

import org.antlr.v4.runtime.ParserRuleContext;
import org.antlr.v4.runtime.tree.ParseTree;
import org.antlr.v4.runtime.tree.ParseTreeProperty;
import org.antlr.v4.runtime.tree.TerminalNode;

import semantic.impl.TypeClass;
import semantic.interfaces.SemanticSymbol;
import semantic.interfaces.SymbolConstant;
import semantic.interfaces.SymbolTable;
import semantic.interfaces.SymbolVariable;


/**
 * 
 * Siga as instru��es e complete os c�digos quando solicitado.
 *
 */

/**
 * Listener que gera c�digo para MIcroJava.
 */
public class CodeGeneratorListener extends MicroJavaBaseListener {

	/**
	 * Tabela de s�mbolos constru�da pela an�lise sem�ntica.
	 */
	private SymbolTable symbolTable;
	
	/**
	 * Mapeamento que associa n�s da �rvore sint�tica com s�mbolos
	 * da tabela de s�mbolos. Esse mapeamento tamb�m � constru�do na
	 * fase de an�lise sem�ntica.
	 */
    private ParseTreeProperty<SemanticSymbol> mapNodeToSymbol;
    
    /**
     * Arquivo de sa�da, onde o c�digo ser� gerado.
     */
	private PrintStream out;
	
	private int numPars; // para calcular n�mero de par�metros de cada m�todo
	private int numVars; // para calcular n�mero de vari�veis em cada m�todo
	
	/**
	 * Pilha usada para comunica��o de informa��es entre os m�todos do Listener.
	 */
	private StringStack stack;

	/**
	 * Contador para gerar labels diferentes.
	 */
	private int labelCounter;

	/**
	 * Construtor.
	 * @param symbolTable Tabela de s�mbolos, constru�da na an�lise sem�ntica.
	 * @param ptp Mapeamento entre n�s da �rvore e s�mbolos da tabela de s�mbolos.
	 * @param out Arquivo de sa�da onde ser� gerado o c�digo.
	 */
	public CodeGeneratorListener(SymbolTable symbolTable,
		    ParseTreeProperty<SemanticSymbol> ptp, PrintStream out) {
		this.symbolTable = symbolTable;
		this.mapNodeToSymbol = ptp;
		this.out = out;
		stack = new StringStack();
		labelCounter = 1;
	}

	/**
	 * Gera novo label.
	 * @return Label gerado (usa n�meros sequenciais para gera label diferente,
	 * a cada chamada.
	 */
	private String genLabel() {
		return "LAB" + labelCounter++;
	}

	
	/**
	 * O m�todo exitProgram � o �ltimo a ser acessado pelo listener
	 * na navega��o da �rvore de sintaxe. O programa assembly completo,
	 * resultante da compila��o, ter� o seguinte formato:
	 * - aloca��o das vari�veis globais (data ...)
	 * - desvio para o in�cio da fun��o main
	 * - c�digo das fun��es definidas
	 * 
	 * O c�digo fornecido para o m�todo exitProgram apresenta um esquema
	 * para construir o programa desejado. Observe que � uma String em que
	 * cada linha do programa termina com "\n", para uma formata��o adequada.
	 * 
	 * O m�todo exitProgram vai ser chamado ap�s o processamento de
	 * todo o programa fonte. Nesse momento, a tabela de s�mbolos
	 * dever� estar com um ambiente no topo da pilha representando
	 * o escopo global do programa, onde s�o definidas as vari�veis
	 * globais, constantes e fun��es.
	 * 
	 * Altere o codigo abaixo para definir numvars com o valor
	 * adequado para o numero de variaveis globais. Para isso,
	 * acesse symbolTable (variavel que representa a tabela
	 * de simbolos), acione o metodo popEnvironment para
	 * desempilhar o ambiente no topo da pilha, e o metodo
	 * numVariaveis para obter o numero de variaveis desse
	 * ambiente, que sera o ambiente global do programa fonte.
	 * Apos fazer essas alteracoes, execute o programa "Piloto.java"
	 * e observe o programa assembly que sera impresso. Esse programa
	 * deve ser o comeco da compilacaoo do programa fonte "input/teste01.txt".
	 * Altere o programa fonte inserindo mais variaveis globais, execute
	 * novamente e observe se o numero de variaveis globais esta sendo
	 * identificado corretamente.
	 * 
	 * OBS: A coleta das variaveis globais e realizada por outros metodos
	 * deste listener.
	 */
	
	public void exitProgram(MicroJavaParser.ProgramContext ctx) {
		int numvars = symbolTable.popEnvironment().numVariaveis();
		String methods = stack.popList("---------\n");
		String result = "data " + numvars + "\n" + "jmp main\n" + methods;
		out.println(result);
//		System.out.print(stack);
	}

	
	/**
	 * Agora vamos analisar a geracaoo de codigo para os metodos.
	 * 
	 * O m�todo exitMethodDecl � chamado no final do processamento
	 * de cada m�todo do programa fonte. Observe a string que ser�
	 * constru�da, como o seguinte formato:
	 * 
	 * ---------------------------------------
	 * label <nome_do_m�todo>
	 * enter <num_par�metros>, <total_vari�veis>
	 * 
	 * <instructions>
	 * 
	 * exit
	 * return
	 * ---------------------------------------
	 * 
	 * O m�todo exitMethodDecl est� empilhando o c�digo associado a
	 * cada m�todo, mas esse c�digo ainda n�o est� sendo processado
	 * pelo m�todo exitProgram, por isso nenhuma informa��o sobre os
	 * m�todos aparecer quando o listener foi executado.
	 */
	
	public void exitMethodDecl(MicroJavaParser.MethodDeclContext ctx) {
		String nome = ctx.IDENT().getText();		
		String instructions = stack.popString();
	
		// OBS: numPars e numVars s�o atributos do pr�prio listener,
		// e ter�o seus valores definidos mais adiante	
		
		String result =
				"\nlabel " + nome + "\n" +
				"enter " + numPars + ", " + numVars + "\n" +
				"\n" +
				instructions +
				"\n" +
				"exit\n" +
				"return\n"
				;
		stack.pushString(result);	
//		System.out.println(stack);
	}
	
	/**
	 * Para ver o que est� acontecendo na pilha, insira o seguinte comando
	 * no final do m�todo exitProgram:
	 * 
	 *   System.out.println(stack);
	 * 
	 * Rode de novo o programa piloto e observe que o conte�do da pilha
	 * ser� impresso ap�s o c�digo gerado em exitProgram.
	 * Veja que a pilha cont�m 2 n�s, um com c�digo gerado para o m�todo main
	 * e outro com c�digo gerado para o m�todo f.
	 * Falta coletar esses c�digos em exitProgram. Para isso, vamos usar um
	 * servi�o da classe StringStack que facilita essa tarefa.
	 */

	
	/**
	 * Retire o coment�rio do m�todo enterProgram, a seguir.
	 * Esse m�todo � executado logo antes de visitar o programa de entrada,
	 * ou seja, bem no in�cio do caminhamento na �rvore.
	 * Um programa pode ter v�rios m�todos, assim n�o se sabe a priori
	 * quantos elementos da pilha estar�o representando os c�digos desses
	 * m�todos. Assim, pushList insere uma "marca" na pilha indicando que
	 * uma sequ�ncia de elementos ser� empilhada, e depois podemos utilizar
	 * um m�todo especial para desempilhar toda essa sequ�ncia de uma vez.
	 * 
	 * Rode novamente o programa Piloto e observe que a inser��o de uma
	 * marca na pilha (>>>>), denotando uma sequ�ncia que poder� ser toda
	 * desempihada em seguida para formar o c�digo completo dos m�todos.
	 */
	public void enterProgram(MicroJavaParser.ProgramContext ctx) {
		stack.pushList();
	}
	
	/**
	 * Agora apague o comando 
	 * 
	 *   System.out.println(stack);
	 * 
	 * no m�todo exitProgram e troque a defini��o de methods por
	 * 
	 * 	  String methods = stack.popList("---------\n");
	 *    
	 * O m�todo popList desempilha tudo que estiver na pilha at� encontrar
	 * a "marca" que foi inserida quando usamos pushList. Uma �nica String
	 * � constru�da concatenando tudo o que foi desempilhado,
	 * com os elementos separados pelo par�metro usado em popList
	 * (nesse caso, "---------\n").
	 * 
	 * Rode o programa piloto novamente e veja o in�cio da gera��o de
	 * c�digo para os m�todos f e main, nessa ordem.
	 */

	
	
	/**
	 * Agora vamos nos ocupar de definir os valores para a instru��o enter
	 * que aparece no in�cio do c�digo de m�todos. Devem ser definidos:
	 * - o n�mero de par�metros do m�todo ("numparams");
	 * - o n�mero total de vari�veis locais, incluindo par�metros ("numvars").
	 * 
	 * Veja as produ��es da gram�tica que podem nos ajudar:
	 * 
	 *   methodDecl : typeOrVoid IDENT '(' formPars ')' varDecl* block ;
	 *   varDecl : type IDENT (',' IDENT)* ';' ;
	 *   formPars : ( formPar (',' formPar)* )?;
	 *   formPar: type IDENT ;
	 *   
	 * Estrat�gia:
	 * - Iniciar as vari�veis numPars e numVars com 0, antes de iniciar
	 * a visita de um m�todo ("enterMethoDecl").
	 * - Cada vez que um par�metro for visitado, incrementar a vari�vel
	 * numPars de 1 unidade ("exitFormPar").
	 * - A cada lista de vari�veis declaradas, incrementar a vari�vel numVars
	 * ("exitVarDecl").
	 * 
	 * Retire o coment�rio dos m�todos a seguir e complete o c�digo.
	 * Depois rode o piloto novamente e confira se a instru��o enter
	 * no in�cio de cada m�todo est� com os valores corretos, de acordo
	 * com o programa fonte fornecido.
	 */


	public void enterMethodDecl(MicroJavaParser.MethodDeclContext ctx) {
		numPars = 0;
		numVars = 0;
	}

	public void exitFormPar(MicroJavaParser.FormParContext ctx) {
		// COMPLETAR:
		// incrementar numPars de uma unidade
		// incrementar numVars de uma unidade
		numPars += 1;
		numVars += 1;
	}
	
	public void exitVarDecl(MicroJavaParser.VarDeclContext ctx) {
	    int n = ctx.IDENT().size(); // n�mero de vari�veis nesta declara��o
		// COMPLETAR:
		// incrementar numVars de n unidades
	    numVars += n;
	}


	
	/**
	 * Vamos come�ar agora a gera��o de c�digo para comandos e express�es.
	 * 
	 * As constantes usadas em express�es est�o associadas � seguinte produ��o,
	 * na gram�tica de MicroJava:
	 * 
	 *   factor:
	 *     valConst    # Value
	 * 
	 * Complete o m�todo exitValue a seguir, para gerar c�digo para constantes.
	 * N�o rode o programa piloto ainda.
	 */

	public void exitValue(MicroJavaParser.ValueContext ctx) {
		String valor = ctx.valConst().getText(); // este � o valor da constante
		
		// Construa String no formato "const <valor>".
		// N�o esque�a de terminar com "\n".
		
		String result = "const " + valor + "\n";
		stack.pushString(result);
	}

	
	/**
	 * Na gram�tica de MicroJava, o corpo de um metodo e um bloco, e um bloco
	 * e uma sequ�ncia de comandos:
	 * 
	 *   methodDecl : typeOrVoid IDENT '(' formPars ')' varDecl* block ;
	 *   block : '{' statement* '}' ;
	 *   
	 * Para reunir os c�digos associados a todos comandos dentro de um bloco,
	 * vamos usar a mesma tecnica apresentada anteriormente, de marcar uma
	 * posicao na pilha no inicio do bloco, e depois desempilhar e combinar
	 * todos os elementos da pilha (cada um e um comando) em um unico codigo
	 * representando todo o bloco. Para isso, retire o comentario dos metodos
	 * a seguir.
	 */
	

	// Marca na pilha o in�cio de sequ�ncia de comandos (bloco).
	public void enterBlock(MicroJavaParser.BlockContext ctx) {
		stack.pushList();
	}

    // Desempilha o c�digo dos comandos do bloco e concatena todos
	public void exitBlock(MicroJavaParser.BlockContext ctx) {
		stack.pushString(stack.popList(""));
	}

	

	/**
	 * Para que os c�digos dentro de um bloco sejam inseridos na posi��o
	 * correta na gera��o de c�digo de m�todos, altere a defini��o de
	 * instructions em exitMethodDecl:
	 * 
	 *   String instructions = stack.popString();
	 *   
	 * Em seguida, rode o programa Piloto. Voc� dever� ver o c�digo para
	 * constantes dentro dos m�todos que usam constantes. Ainda n�o est�
	 * sendo gerado c�digo para comando de atribui��o.
	 */

	
	
	/**
	 * Um identificador simples � definido na gram�tica de MicroJava
	 * pela produ��o:
	 * 
	 *   designator :
	 *     IDENT        # DesigId
	 * 
	 * O m�todo abaixo trata todos os casos de gera��o de c�digo para
	 * um idetificador simples:
	 * - pode ser constante, m�todo ou vari�vel;
	 * - se for vari�vel, pode ser local ou global;
	 * - se for local, pode ser leitura (load) ou escrita (store),
	 * dependendo se for a �ltima instru��o de um comando de atribui��o;
	 * - se for global, pode ser leitura (getStatic) ou escrita (putstatic),
	 * dependendo se for a �ltima instru��o de um comando de atribui��o.
	 * 
	 * Procure entender o c�digo.
	 * Retire o coment�rio e rode o programa Piloto.
	 * Observe que o c�digo gerado para os identificadores est� correto,
	 * embora possa aparecer fora da ordem correta em comandos de atribui��o.
	 */
	

	public void exitDesigId(MicroJavaParser.DesigIdContext ctx) {
		TerminalNode treeNode = ctx.IDENT();
		SemanticSymbol s = mapNodeToSymbol.get(treeNode);
		if (s.isConstant()) { // troca o identificar pelo valor da constante
			SymbolConstant sc = (SymbolConstant) s;
			String result = "const " + sc.getValue() + "\n";
			stack.pushString(result);
		} else if (s.isMethod()) {
			// tratado na alternativa Desig
		} else { // is variable
			SymbolVariable sv = (SymbolVariable) s;
			boolean isGlobal = sv.getLevel() == 1;
			int offset = sv.getOffset();
			ParserRuleContext prc = ctx.getParent(); // no pai na arvore
			String comando;
			if (prc instanceof MicroJavaParser.AssignContext) {
				// no pai e atribuicaoo
				if (isGlobal) { // global
					comando = "putstatic ";
				} else { // local
					comando = "store ";
				}
			} else {
				// no pai nao e atribuicao
				if (isGlobal) { // global
					comando = "getstatic ";
				} else { // local
					comando = "load ";
				}
			}
			String result = comando + offset + "\n";
			stack.pushString(result);
		}
	}


	
	/**
	 * As opera��es de soma e subtra��o s�o representadas na gram�tica por:
	 * 
	 *   expr:
	 *     expr op=('+'|'-') term     # AddSub
	 * 
	 * O m�todo abaixo implementa a gera��o de c�digo para soma e subtra��o.
	 * Retire o coment�rio, rode o programa piloto e verifique se o c�digo
	 * est� sendo gerado corretamente para este caso.
	 */


	public void exitAddSub(MicroJavaParser.AddSubContext ctx) {
		String op = ctx.op.getText();
		String op2;
		if (op.equals("+")) {
			op2 = "add";
		} else {
			op2 = "sub";
		}
		String s2 = stack.popString();
		String s1 = stack.popString();
		String result = s1 + s2 + op2 + "\n";
		stack.pushString(result);
	}
	
	/**
	 * As opera��es *, / e % s�o representadas na gram�tica por:
	 * 
	 *   term:
	 *     term op=('*'|'/'|'%') factor   # MulDiv
	 * 
	 * Usando o m�todo exitAddSub como modelo, construa um m�todo exitMulDiv
	 * para gerar c�digo para essas opera��es. 
	 * 
	 * public void exitMulDiv(MicroJavaParser.MulDivContext ctx) {
	 *    ...
	 * }
	 * 
	 * Rode o programa piloto e verifique se o c�digo est� sendo gerado
	 * corretamente para este caso.
	 */
	public void exitMulDiv(MicroJavaParser.AddSubContext ctx) {
		String op = ctx.op.getText();
		String op2;
		if (op.equals("*")) {
			op2 = "mul";
		} else {
			op2 = "div";
		}
		String s2 = stack.popString();
		String s1 = stack.popString();
		String result = s1 + s2 + op2 + "\n";
		stack.pushString(result);
	}

	

	/**
	 * Em um comando de atribui��o simples como "d = 12", o c�digo para
	 * a express�o do lado direito deve ser gerado primeiro, e depois gerado
	 * um c�digo para alterar o valor da mem�ria.
	 * 
	 * Retire o coment�rio, rode o programa piloto e observe que agora
	 * as instru��es devem estar na ordem esperada para o c�digo de
	 * comandos de atribui��o (simples).
	 */


	public void exitAssign(MicroJavaParser.AssignContext ctx) {
		String s1 = stack.popString(); // ultimo comando empilhado
		String s2 = stack.popString(); // comando anterior ao acima
		String result = "";
		result += s1 + s2;
		
		ParseTree node = ctx.getChild(0);
		if (node instanceof MicroJavaParser.DesigDotContext ||
				node instanceof MicroJavaParser.DesigArrayContext) {
			result += stack.popString();
		}
		
		stack.pushString(result);
	}	

	/**
	 * Quando designadores mais complexos como "x1.prox" ou "V[i]" s�o usados
	 * no lado esquerdo de uma atribui��o, o c�digo deve estar preparado para
	 * processar mais um elemento na pilha, associado a instru��es que realizam
	 * leitura na mem�ria antes da escrita. Assim, o m�todo exitAssign dever�
	 * sofrer pequenas altera��es, como apresentado abaixo.
	 * Antes de iniciarmos o tratamento de designadores mais complexos,
	 * acrescente o c�digo abaixo no m�todo exitAssign, logo ap�s a declara��o
	 * de result:
	 */
	 
/*	
	ParseTree node = ctx.getChild(0);
	if (node instanceof MicroJavaParser.DesigDotContext ||
			node instanceof MicroJavaParser.DesigArrayContext) {
		result += stack.popString();
	}
*/
	
	
	/**
	 * Os m�todos abaixo geram c�digo para designadores envolvendo
	 * acesso a campos de classes e arrays.
	 * Retire o coment�rio, insira no arquivo teste01.txt casos de
	 * uso desses designadores, rode o programa piloto e confira se
	 * o c�digo est� sendo gerado corretamente.
	 */


	public void exitDesigDot(MicroJavaParser.DesigDotContext ctx) {
		TerminalNode treeNode = ctx.IDENT();
		SemanticSymbol s = mapNodeToSymbol.get(treeNode);
		SymbolVariable sv = (SymbolVariable) s;
		int i = sv.getOffset();
		ParserRuleContext prc = ctx.getParent();
		String result;
		if (prc instanceof MicroJavaParser.AssignContext) {
			result = "putfield " + i + "\n";
		} else {
			String s1 = stack.popString();
			result = s1 + "getfield " + i + "\n";
		}
		stack.pushString(result);		
	}

	public void exitDesigArray(MicroJavaParser.DesigArrayContext ctx) {
		ParserRuleContext prc = ctx.getParent();
		boolean b = prc instanceof MicroJavaParser.AssignContext;
		String s2 = stack.popString();
		String s1 = stack.popString();
		String result = s1 + s2;
		if (! b) {
			result += "aload\n";
		}
		stack.pushString(result);
		if (b) {
			stack.pushString("astore\n");
		}
	}
	

	/**
	 * Uma condi��o em MicroJava pode aparecer dentro de um comando condicional
	 * ou dentro de um comando de repeti��o. Na gram�tica, tem a forma:
	 * 
	 *   condition : expr relop expr ;
	 *   
	 * Independente se a condi��o for usada em comando IF ou WHILE, o c�digo
	 * a ser gerado deve avaliar as 2 express�es envolvidas e depois realizar
	 * um desvio condicional. O desvio tem 2 componentes:
	 * - a opera��o de compara��o (eq, ne, gt, ge, lt, le);
	 * - o label para onde ir� desviar, caso a opera��o seja avaliada com
	 * resultado verdadeiro.
	 * 
	 * O m�todo exitCondition a seguir gera c�digo para condi��es.
	 * Para saber qual opera��o de compara��o � utilizada, consulta relop.
	 * Espera que o c�digo de ambas as express�es estejam na pilha.
	 * E espera que o nome do label para onde dever� desviar tamb�m esteja
	 * na pilha.
	 * 
	 * Em seguida, � apresentada a gera��o de c�digo para comando WHILE,
	 * que usa o c�digo de condi��o discutido acima. Produ��o na gram�tica:
	 * 
	 *   'while' '(' condition ')' statement       # While
	 * 
	 * No in�cio da visita a um n� que representa comando WHILE na �rvore,
	 * s�o gerados 3 labels diferentes, que s�o empilhados.
	 * Os labels ir�o estar associados a:
	 * - posi��o antes de testar a condi��o;
	 * - posi��o depois do t�rmino do while;
	 * - posi��o onde come�a o bloco de comandos que pertence ao while.
	 * 
	 * Como os r�tulos s�o diferentes, poderiam estar associados a qualquer
	 * uma das 3 posi��es que devem ser marcadas em um comando while.
	 * Entretanto, fica mais f�cil assumir que o �ltimo r�tulo a ser empilhado
	 * est� associado � posi��o onde come�a o comando ou bloco de comandos
	 * interno ao while, porque o primeiro componente do while a ser processado
	 * � sua condi��o. Quando a condi��o � processada, como discutimos acima,
	 * pega-se na pilha um label que indica a posi��o do desvio condicional.
	 * E em um comando while, caso a condi��o resulte em verdadeiro, deve-se
	 * fazer um desvio para o in�cio do comando ou bloco de comandos internp
	 * ao while.
	 * 
	 * Retire os coment�rios, definindo os m�todos para gera��o de c�digo
	 * para condi��es e comandos WHILE. Insira comandos while no arquivo de
	 * entrada e rode o programa piloto. Verifique se o c�digo gerado est�
	 * correto.
	 */
	

	public void exitCondition(MicroJavaParser.ConditionContext ctx) {
		String op = ctx.relop().getText();
		String op2;
		if (op.equals("<")) {
			op2 = "lt";
		} else if (op.equals(">")) {
			op2 = "gt";
		} else if (op.equals("==")) {
			op2 = "eq";
		} else if (op.equals("!=")) {
			op2 = "ne";
		} else if (op.equals("<=")) {
			op2 = "le";
		} else {
			op2 = "ge";
		}
		String exp2 = stack.popString();
		String exp1 = stack.popString();
		String label = stack.peekString();
		String result =
			exp1 +
			exp2 +
			"j" + op2 + " " + label + "\n";
		stack.pushString(result);
	}

	public void enterWhile(MicroJavaParser.WhileContext ctx) {
		stack.pushString(genLabel()); // label antes da condi��o
		stack.pushString(genLabel()); // label depois do while
		stack.pushString(genLabel()); // label in�cio do bloco
	}

	public void exitWhile(MicroJavaParser.WhileContext ctx) {
		String statement = stack.popString(); // c�digo do bloco
		String cond = stack.popString();      // c�digo da condi��o 
		String label1 = stack.popString();    // label in�cio do bloco
		String label2 = stack.popString();    // label depois do while
		String label3 = stack.popString();    // label antes da condi��o
		String result = "label " + label3 + "\n" 
		+ cond 
		+ "jmp " + label2 + "\n" 
		+ "label " + label1 + "\n" 
		+ statement 
		+ "jmp " + label3 + "\n" 
		+ "label " + label2 + "\n";
		stack.pushString(result);
	}
	
	
	/**
	 * Tomando como base os m�todos para gera��o de c�digo para WHILE,
	 * implemente a gera��o de c�digo para comando IF e IF-ELSE.
	 * 
	 * Retire os coment�rios dos m�todos a seguir, complete o c�digo
	 * onde � solicitado e finalmente teste se funcionou a gera��o de c�digo
	 * para IF e IF-ELSE, inserindo exemplos desses comandos
	 * no arquivo de entrada.
	 */


	// O c�digo deste m�todo j� est� completo:
	public void enterIf(MicroJavaParser.IfContext ctx) {
		stack.pushString(genLabel()); // label posi��o ap�s o IF
		if (ctx.st2 != null) {
			// somente se tiver cl�usula ELSE...
			stack.pushString(genLabel()); // label posi��o comando FALSE
		}
		stack.pushString(genLabel()); // label posi��o comando TRUE
		// Da mesma forma que no comando WHILE, � interessante assumir
		// que o �ltimo label empilhado se refere ao in�cio do comando
		// ou bloco de comandos a ser executado se a condi��o for verdadeira,
		// pois esse label ser� usado pelo m�todo que gera c�digo para condi��o.
	}

	public void exitIf(MicroJavaParser.IfContext ctx) {
		if (ctx.st2 == null) {
			// se n�o tiver cl�usula ELSE...
			String statement1 = stack.popString(); // comando C1 a ser executado
			String cond = stack.popString();       // condi��o
			String label1 = stack.popString();     // in�cio de C1
			String label2 = stack.popString();     // ap�s o IF
			String result = cond 
					+ "\njmp " + label2 
					+ "\nlabel " + label1 
					+ "\n" + statement1 
					+ "\nlabel " + label2;
			stack.pushString(result);
		} else {
			// somente se tiver cl�usula ELSE...
			String statement2 = stack.popString(); // comando C2 (se condi��o false)
			String statement1 = stack.popString(); // comando C1 (se condi��o true)
			String cond = stack.popString();       // condi��o
			String label1 = stack.popString();     // in�cio de C1
			String label2 = stack.popString();     // in�cio de C2
			String label3 = stack.popString();     // ap�s o IF
			String result = cond +
					"\njmp " + label2
					+"\nlabel " + label1
					+"\n" + statement1
					+"\nlabel " + label2
					+"\n" + statement2
					+"\nlabel " + label3;
			stack.pushString(result);
		}
	}

	
	/**
	 * A tarefa de implementar gera��o de c�digo para comando condicional
	 * foi a �ltima deste tutorial. A seguir, s�o apresentados m�todos para
	 * gerar c�digo para quase todos os demais comandos da linguagem MicroJava.
	 * Basta tirar os coment�rios para usar.
	 */
	
	
	public void enterDesig(MicroJavaParser.DesigContext ctx) {
		if (ctx.actPars() != null) {
			stack.pushList();
		}
	}
	

	public void exitDesig(MicroJavaParser.DesigContext ctx) {
		if (ctx.actPars() != null) {
			String args = stack.popList("");
			String result =
					args +
					"call " + ctx.start.getText() + "\n"
					;
			stack.pushString(result);
		}
	}
	
	public void exitNew(MicroJavaParser.NewContext ctx) {
		TerminalNode treeNode = ctx.IDENT();
		TypeClass type = (TypeClass) (mapNodeToSymbol.get(treeNode).getSemanticType());
		int size = type.getEnvironment().numVariaveis() * 4;
		String result;
		if (ctx.expr() != null) { // aloca array
			String numExp = stack.popString();
			result =
					numExp +
					"newaray 1\n"
					;
		} else {
			result = "new " + size + "\n";
		}
		stack.pushString(result);
	}

	public void exitReturn(MicroJavaParser.ReturnContext ctx) {
		String exp = stack.popString();
		String result =
				exp +
				"exit\n" +
				"return\n"
				;
		stack.pushString(result);
	}

	public void enterFuncall(MicroJavaParser.FuncallContext ctx) {
		stack.pushList();
	}

	public void exitFuncall(MicroJavaParser.FuncallContext ctx) {
		String args = stack.popList("");
		String result =
				args +
				"call " + ctx.start.getText() + "\n"
				;
		stack.pushString(result);
	}
	
}
