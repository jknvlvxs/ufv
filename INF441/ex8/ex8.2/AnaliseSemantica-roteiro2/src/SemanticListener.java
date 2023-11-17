
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
     */
    public SemanticListener(MicroJavaParser parser, SymbolTable symbolTable, SemanticFactory semanticFactory) {
    	this.parser = parser;
    	this.symbolTable = symbolTable;
    	this.semanticFactory = semanticFactory;
    	symbolTable.pushEnvironment();
    }
    

    /**
     * Nesta segunda parte da an�lise sem�ntica, ser�o analisados os USOS
     * dos s�mbolos em programas.
     */
    

    /**
     * Come�aremos com o comando de atribui��o. Na gram�tica:
     * 
     *     statement :    designator '=' expr ';'    # Assign
     *     ...
     *     
     * Ao visitar o comando ap�s a an�lise de seus componentes, espera-se
     * que na pilha stack haja 2 tipos armazenados: o tipo associado ao lado
     * esquerdo da atribui��o, e o tipo associado � express�o do lado direito.
     */
    public void exitAssign(MicroJavaParser.AssignContext ctx) {
    	// TODO: traduza o pseudo-c�digo para Java
    	
    	// Desempilhe (de stack) o tipo da express�o.
    	// Lembre que a pilha stack � gen�rica e armazena Object, por isso
    	// pode ser necess�ria uma convers�o expl�cita para SemanticType
    	SemanticType st = (SemanticType) stack.pop();
    	
    	// Desempilhe (de stack) o tipo associado ao lado esquerdo
    	SemanticType stL = (SemanticType) stack.pop();
    	
    	// Verifique se os tipos s�o compat�veis, usando o m�todo
    	// compatibleTypes. O primeiro par�metro deve ser o tipo
    	// que vai ser alvo da atribui��o.
    	// Para emitir msg de erro com posi��o correta, use
    	// o token ctx.getStart()
    	if(!compatibleTypes(stL,st)) {
			emitErrorMessage(ctx.getStart(), "Incompatibilidade de tipos");
		}
    }

    
    /**
     * Vamos analisar agora produ��es que constroem as express�es.
     * 
     * Come�amos com um simples identificador.
     * 
     *     designator :    IDENT    # DesigId
     *
     * O simbolo deve ser procurado na tabela e seu tipo deve ser
     * empilhado em stack, para ser usado nos passos seguintes da
     * an�lise sem�ntica.
     * 
     * Escreva o c�digo que falta, de acordo com as instru��es.
     */
	public void exitDesigId(MicroJavaParser.DesigIdContext ctx) {
		Token t = ctx.IDENT().getSymbol(); // Token associado ao identificador
		String nome = t.getText();         // Nome do identificador
		
		// TODO: traduza o pseudo-c�digo a seguir para Java
		
		// Procure s�mbolo na tabela, usando o nome do s�mbolo.
		SemanticSymbol s = symbolTable.getSymbol(nome);

		// Se encontrou, empilhe o tipo do s�mbolo usando m�todo getSemanticType.
		// Se n�o encontrou, emita msg de erro; mas n�o pode ficar sem empilhar
		// um tipo qualquer, pois os outros m�todos da an�lise v�o assumir
		// que h� um tipo no topo da pilha - pode empilhar TypeInteger ou TypeNull,
		// usando os m�todos dispon�veis para isso na tabela de s�mbolos.
		if(s != null) {
			stack.push(s.getSemanticType());
		} else {
			stack.push(symbolTable.getNullType());
			emitErrorMessage(t, "Tipo não identificado: " + nome);
		}
	}
	

    /**
     * Teste o programa declarando algumas var��veis e, dentro de m�todos,
     * usando comandos de atribui��o simples, com constantes e vari�veis. Ex:
     * 
     *     x = 123;
     *     y = x;
     *     
     * Insira casos em que o tipo do lado esquerdo n�o � compat�vel com
     * a express�o, para testar se a an�lise est� detectando esses erros.
     */

    
    /**
     * Vamos analisar agora outras produ��es que constroem as express�es.
     * 
     *     expr:
     *       op='-'? term             # OneTerm
     *     | expr op=('+'|'-') term   # AddSub
     */

    
    /**
     * No caso da produ��o # OneTerm:
     * 
     * - se o operador "-" n�o foi utilizado, n�o h� nada a se fazer;
     * - se o operador "-" foi utilizado, o tipo da express�o no topo da pilha
     * deve ser Integer ou Float, caso contr�rio emitir msg de erro.
     * 
     * Lembre que o tipo da express�o n�o vai mudar, e o mesmo deve continuar
     * no topo da pilha. Se desempilhar, empilhe o tipo novamente.
     * Ou ent�o, apenas consulte o topo da pilha usando stack.peek().
     */
    public void exitOneTerm(MicroJavaParser.OneTermContext ctx) {    	
    	// TODO: escreva o c�digo discutido no coment�rio acima, em Java.
    	// Para testar se "-" foi utilizado, verifique: ctx.op != null.
    	// Para testar se um tipo st � Integer ou Float, verifique:
    	// st.isInteger() , st.isFloat().
    	if(ctx.op != null) {
    		SemanticType st = (SemanticType) stack.peek();

    		if(!st.isInteger() && !st.isFloat()) {
    			emitErrorMessage(ctx.op, "O tipo esperado deve ser Integer ou Float");
    		}
    	}
    }
    
    
    /**
     * Teste o programa usando operador un�rio "-".
     * Procure explorar situa��es de erro.
     */

    
    /**
     * Analisaremos agora o caso da produ��o # AddSub.
     * Complete o c�digo.
     */
    public void exitAddSub(MicroJavaParser.AddSubContext ctx) {
    	// st2 ter� o tipo da express�o da direita,
    	// e st1 ter� o tipo da express�o da esquerda
    	SemanticType st2 = (SemanticType) stack.pop();
    	SemanticType st1 = (SemanticType) stack.pop();
    	Token t = ctx.getStart(); // token usado para msgs de erro
    	
		// TODO: traduza o pseudo-c�digo a seguir para Java
    	
    	// Se st1 n�o � Integer nem Float ou st2 n�o � Integer nem Float,
    	// emitir msg de erro.    	
    	// Se st1 ou st2 for Float, empilhar em stack um tipo Float,
    	// caso contr�rio, empilhar um tipo Integer
    	if((!st1.isInteger() && !st1.isFloat()) || (!st2.isInteger() && !st2.isFloat())) {
    		emitErrorMessage(t, "O tipo esperado deve ser Integer ou Float");
    	} else if(st1.isFloat() || st2.isFloat()) {
    		stack.push(symbolTable.getFloatType());
    	} else {
    		stack.push(symbolTable.getIntegerType());
    	}

    }
    
    
    /**
     * Mais produ��es ligadas a express�es:
     * 
     *     term:
     *       factor                         # OneFactor
     *     | term op=('*'|'/'|'%') factor   # MulDiv
     *     
     * No caso de # OneFactor, nada � necess�rio fazer.
     * No caso de # MultDiv, c�digo semelhante a # AddSub resolve a an�lise.
     */
    public void exitMulDiv(MicroJavaParser.MulDivContext ctx) {
    	// TODO: escreva c�digo semelhante ao de # AddSub
    	// Diferen�a: operador % s� � aplicado a operandos inteiros.
    	SemanticType st2 = (SemanticType) stack.pop();
    	SemanticType st1 = (SemanticType) stack.pop();
    	Token t = ctx.getStart();
    	
    	// Diferen�a: operador % s� � aplicado a operandos inteiros.
    	if( ("%".equals(ctx.op.getText())) && !(st1.isInteger() && st2.isInteger()) ){
    		emitErrorMessage(t, "O tipo esperado deve ser Integer");
    	}
    	
    	
    	if((!st1.isInteger() && !st1.isFloat()) || (!st2.isInteger() && !st2.isFloat())) {
    		emitErrorMessage(t, "O tipo esperado deve ser Integer ou Float");
    	} else if(st1.isFloat() || st2.isFloat()) {
    		stack.push(symbolTable.getFloatType());
    	} else {
    		stack.push(symbolTable.getIntegerType());
    	}
    }


    /**
     * Teste o programa usando operadores: + - * / % .
     * Procure explorar situa��es de erro.
     */


    /**
     * Continuando a analisar produ��es ligadas a express�es:
     * 
     *     factor:
     *       valConst                        # Value
     *     | 'new' IDENT ('[' expr ']')?     # New
     *     ...
     * 
     * O caso # Value j� foi tratado na primeira parte da an�lise sem�ntica.
     */
    
    
    /**
     * A produ��o # New est� associada ao uso do comando "new". Exemplos:
     * 
     *     ... new C
     *     ... new C[i]
     * 
     * Para realizar a an�lise sem�ntica:
     * 
     * - Verificar se � new simples ou de array. Para isso, verificar:
     * ctx.expr != null.
     * 
     * - Se for new de array, desempilhar o tipo que estiver no topo
     * de stack e verificar se � Integer (�ndice do array); caso contr�rio,
     * emitir msg de erro. No caso de erro, use ctx.expr().start
     * para o token da msg.
     * Mesmo se detectar o erro acima, as an�lses a seguir devem continuar
     * sendo realizadas.
     * 
     * - Procurar o s�mbolo IDENT na tabela.
     * Se n�o encontrar, emitir msg de erro.
     * 
     * - Caso contr�rio (se encontrou o s�mbolo na tabela),
     * verificar se a categoria � Class (s� pode new para nome de classe).
     * Se n�o for, emitir msg de erro.
     * 
     * - Caso contrario (encontrou s�mbolo e � Class),
     * obenha o tipo do simbolo. Empilhe esse tipo, ou se for new de array,
     * empilhe um tipo array com esse tipo dentro (use a f�brica para criar
     * um tipo array).
     * 
     * OBS: Nos casos de erro por n�o encontrar o s�mbolo na tabela ou
     * por ele n�o ser Class, ainda assim um tipo deve ser empilhado,
     * para n�o gerar erros nos outros m�todos, que esperam esse tipo.
     * Nestes casos, � sugerido empilhar um tipo Integer ou Null.
     */
	public void exitNew(MicroJavaParser.NewContext ctx) {
		// TODO: escreva c�digo de acordo com a discuss�o no coment�rio.
    	if (ctx.expr() != null) {
    		SemanticType st = (SemanticType) stack.pop();
    		if(!st.isInteger()) {
    			emitErrorMessage(ctx.expr().start, "O tipo esperado do índice deve ser Integer");
    		}
    	}
		Token t = ctx.IDENT().getSymbol();
		String nome = t.getText();
		SemanticSymbol s = symbolTable.getSymbol(nome);
		
		if(s == null) {
			stack.push(symbolTable.getNullType());
			emitErrorMessage(t, "Tipo não declarado: " + nome);
		} else if(!s.isClass()) {
			stack.push(symbolTable.getNullType());
			emitErrorMessage(t, "Tipo não declarado " + nome + " não é uma classe");
		} else {
			if (ctx.expr() != null) {
				stack.push(semanticFactory.createArrayType(s.getSemanticType()));
			} else {
				stack.push(s.getSemanticType());
			}
		}
	}
	
	
	/**
	 * Teste o programa usando new em express�es.
	 * Procure testar situa��es que cubram os poss�veis erros sem�nticos.
	 */

	
	/**
	 * Produ��es que envolvem designadores, que podem aparecer do lado
	 * esquerdo ou direito de uma atribui��o:
	 * 
	 *     designator :
	 *       IDENT                     # DesigId
	 *     | designator '.' IDENT      # DesigDot
	 *     | designator '[' expr ']'   # DesigArray
	 *     
	 * O caso # DesigId j� foi tratado neste roteiro.
	 */
	
	
	/**
	 * A produ��o # DesigDot est� associada ao uso de atributos de classes.
	 * 
	 *     designator :
	 *     ...
	 *     | designator '.' IDENT      # DesigDot
	 *     
	 * Exemplo:
	 * 
	 *     val.prox. ... .neg
	 * 
	 * Observe que a produ��o � formada por 2 componentes:
	 * - designator � uma estrutura recursiva que deve ter sido analisada em
	 * outros casos neste roteiro, e o resultado da an�lise deve estar na pilha;
	 * - IDENT � um nome que pode ser consultado neste momento da an�lise.
	 * 
	 * Complete o c�digo abaixo para an�lise sem�ntica desses casos.
	 */
	public void exitDesigDot(MicroJavaParser.DesigDotContext ctx) {
		// No topo de stack deve estar o tipo do designator, que � desempilhado
		SemanticType st = (SemanticType) stack.pop();
		if (!st.isClass()) {
			// Se o tipo n�o for classe � um erro
			emitErrorMessage(ctx.getStart(), "Tipo da express�o deve ser uma classe");
			// Empilha tipo qualquer, para n�o gerar erros nas etapas seguintes
			stack.push(symbolTable.getIntegerType());
		} else { // o tipo � uma classe
			TypeClass tc = (TypeClass) st; // convers�o expl�cita segura
			
			// Obt�m o nome do atributo a ser acessado
			Token t = ctx.IDENT().getSymbol();
			String nome = t.getText();
			
			// TODO: completar o c�digo
			
			// O nome do atributo deve ser procurado NO AMBIENTE DA CLASSE ASSOCIADA
			// e n�o no ambiente corrente da tabela de s�mbolos,
			// diferente de outros casos neste roteiro.
			
			// Se n�o encontrou o atributo, emitir msg de erro
			// e empilhar tipo qualquer.
			
			// Caso contr�rio (encontrou o atributo dentro da classe),
			// empilhar o tipo desse atributo.
			Environment env = tc.getEnvironment();
			
			if(env.getSymbol(nome) == null) {
				stack.push(symbolTable.getNullType());
				emitErrorMessage(t, "Atributo não encontrado :" + nome);
			} else {
				stack.push(env.getSymbol(nome).getSemanticType());
			}
		}
	}

	
	/**
	 * Teste o programa usando atributos de classes.
	 * Procure testar situa��es que cubram os poss�veis erros sem�nticos.
	 */

	
	/**
	 * A produ��o # DesigArray est� associada ao uso de arrays.
	 * 
	 *     designator :
	 *     ...
	 *     | designator '[' expr ']'   # DesigArray
	 *     
	 * Exemplo:
	 * 
	 *     neg[i-1]
	 * 
	 * Observe que a produ��o � formada por 2 componentes:
	 * - expr � uma express�o que deve ter sido analisada em outros casos
	 * neste roteiro, e o resultado da an�lise deve estar na pilha;
	 * - designator � uma estrtura recursiva que deve tamb�m deve ter sido
	 * analisada em outros casos neste roteiro, e o resultado da an�lise
	 * deve estar tamb�m na pilha;
	 * 
	 * Complete o c�digo abaixo para an�lise sem�ntica desses casos.
	 */
	public void exitDesigArray(MicroJavaParser.DesigArrayContext ctx) {
		// st2 � o tipo da express�o dentro dos colchetes
		// e st1 � o tipo do designador
		SemanticType st2 = (SemanticType) stack.pop();
		SemanticType st1 = (SemanticType) stack.pop();
		
		// TODO: completar o c�digo

		// Se st2 n�o � Integer, emitir msg de erro.
		// Mesmo se detectar esse erro, a an�lise abaixo deve ser realizada.
		
		// Se st1 n�o � array, emitir msg de erro e empilhar tipo qualquer.
		
		// Caso contr�rio (st1 � array), empilhar o tipo dos elementos do array.
		if(!st2.isInteger()) {
			stack.push(symbolTable.getNullType());
			emitErrorMessage(ctx.getStart(), "O indice deve ser um valor do tipor Integer");
		}
		
		if(!st1.isArray()) {
			stack.push(symbolTable.getNullType());
			String nome = ctx.designator().getText();
			emitErrorMessage(ctx.getStart(), "Não é um array: " + ctx.designator().getText());
		} else {
			TypeArray array = (TypeArray) st1;
			stack.push(array.getInnerType());
		}
	}
	
		
	/**
	 * Teste o programa acessando elementos de arrays.
	 * Procure testar situa��es que cubram os poss�veis erros sem�nticos.
	 */

	
	/**
	 * M�todos podem ser chamados como comandos, ou dentro de express�es.
	 * Os c�digos abaixo tratam esses casos. O c�digo j� est� completo.
	 * Procure estudar e entender o c�digo.
	 */

	
	/**
	 * Processamento dos argumentos usados em chamadas de m�todos.
	 */
	public void exitActPars(MicroJavaParser.ActParsContext ctx) {
		// empilhar o n�mero de par�metros reais, para a an�lise poder saber
		// quantos elementos na pilha s�o associados aos tipos dos par�metros reais
		stack.push(ctx.expr().size());
	}

	
	/**
	 * Caso em que m�todo � chamado dentro de express�o
	 */
	public void exitDesig(MicroJavaParser.DesigContext ctx) {
		if (ctx.actPars() != null) {
			processFunCall(ctx.designator(), ctx.actPars());
		}
	}

	
	/**
	 * Caso em que m�todo � chamdao como um comando.
	 * Veja que a �nica diferen�a � que o tipo retornado pelo m�todo
	 * � desempilhado, quando � um comando, pois n�o mais precisar�
	 * ser usado dentro de uma express�o.
	 */
	public void exitFuncall(MicroJavaParser.FuncallContext ctx) {
		processFunCall(ctx.designator(), ctx.actPars());
		stack.pop(); // desempilha tipo de retorno do m�todo
	}

	
	/**
	 * C�digo que analisa chamada de m�todos, tanto para o caso em que s�o
	 * usados como comandos, quanto dentro de express�es.
	 */
	void processFunCall(MicroJavaParser.DesignatorContext ctx1, MicroJavaParser.ActParsContext ctx2) {
		// desempilha n�mero de argumentos usados
		int numArgs = (int) stack.pop();
		SemanticType[] args = new SemanticType[numArgs];
		// desempilha tipos dos argumentos e coloca em ordem em um array
		for (int i = 1; i <= numArgs; ++i) {
			args[numArgs - i] = (SemanticType) stack.pop();
		}
		// desempilha elemento que deveria ser tipo do m�todo usado
		SemanticType st = (SemanticType) stack.pop();
		if (!st.isMethod()) {
			// programa pode ter usado s�mbolo que n�o era m�todo
			emitErrorMessage(ctx1.start, "Deveria ser um m�todo");
			stack.push(symbolTable.getVoidType()); // tipo de retorno artificial...
		} else {
			TypeMethod mt = (TypeMethod) st;
			int numFormPar = mt.getParams().size();
			if (numFormPar != numArgs) {
				emitErrorMessage(ctx1.start, "N�mero incoreto de par�metros");
			}
			int n = numArgs;
			if (n > numFormPar) {
				n = numFormPar;
			}
			for (int i = 0; i < n; ++i) {
				SemanticType st1 = mt.getParams().get(i);
				SemanticType st2 = args[i];
				if (!compatibleTypes(st1, st2)) {
					Token t = ctx2.expr().get(i).start;
					emitErrorMessage(t, "Tipo incompat�vel com o par�metro do m�todo");
				}
			}
			// empilha tipo de retorno
			stack.push(mt.getReturnType());
		}
	}

    
	/**
	 * Teste o programa usando chamadas de m�todos.
	 * Procure testar situa��es que cubram os poss�veis erros sem�nticos.
	 */

	
	
    /**------------------------------------------------------------------------
     * 
     * T�rmino do roteiro.
     * Os c�digos abaixo j� foram discutidos no roteiro anterior.
     * 
     *-----------------------------------------------------------------------*/
	
   
	
    public void exitTypeWithoutArray(MicroJavaParser.TypeWithoutArrayContext ctx) {
    	SemanticType st = searchType(ctx.IDENT().getSymbol());
    	stack.push(st);
    }

    public void exitTypeWithArray(MicroJavaParser.TypeWithArrayContext ctx) {
    	SemanticType st = searchType(ctx.IDENT().getSymbol());
        SemanticType st2 = semanticFactory.createArrayType(st);
    	stack.push(st2);
    }
    
	public void exitConstInt(MicroJavaParser.ConstIntContext ctx) {
		stack.push(symbolTable.getIntegerType());
	}
	
	public void exitConstReal(MicroJavaParser.ConstRealContext ctx) {
		stack.push(symbolTable.getFloatType());		
	}
	
	public void exitConstStr(MicroJavaParser.ConstStrContext ctx) {
		stack.push(symbolTable.getCharType());
	}

    public void exitConstDecl(MicroJavaParser.ConstDeclContext ctx) {
    	SemanticType st2 = (SemanticType) stack.pop();
    	SemanticType st1 = (SemanticType) stack.pop();
        if (st1 != st2)
        {
            emitErrorMessage(ctx.IDENT().getSymbol(), "Incompatibilidade de tipos");
        } else {
        	SemanticSymbol s = symbolTable.addSymbolConstant(ctx.IDENT().getText(), st1, null);
            if (s == null) {
            	Token t = ctx.IDENT().getSymbol();
            	emitErrorMessage(t, "Identificador j� declarado: " + t.getText());
            }
        }
    }
    
    public void exitVarDecl(MicroJavaParser.VarDeclContext ctx) {
    	SemanticType st = (SemanticType) stack.pop();
    	for(TerminalNode tn: ctx.IDENT()) {
    		SemanticSymbol s = symbolTable.addSymbolVariable(tn.getText(), st);
    		if (s == null) {
    			emitErrorMessage(tn.getSymbol(), "Identificador j� declarado: " + tn.getText());
    		}
    	}
    }
    
    public void enterClassDecl(MicroJavaParser.ClassDeclContext ctx) {
    	Token t = ctx.IDENT().getSymbol();
        SemanticSymbol s = symbolTable.addSymbolClass(t.getText());
        if (s == null) {
        	emitErrorMessage(t, " Identificador j� declarado: " + t.getText());
        	stack.push(null);
        } else {
            stack.push(s.getSemanticType());
        }
        symbolTable.pushEnvironment();
    }

    public void exitClassDecl(MicroJavaParser.ClassDeclContext ctx) {
        Environment e = symbolTable.popEnvironment();
        TypeClass tc = (TypeClass) stack.pop();
        if (tc != null) {
            tc.setEnvironment(e);
        }
    }
    
    public void enterMethodDecl(MicroJavaParser.MethodDeclContext ctx) {
    	stack.push(ctx.IDENT().getSymbol());
    }
    
    public void exitTypeOrVoid(MicroJavaParser.TypeOrVoidContext ctx) {
    	if (ctx.start.getText().equals("void")) {
    		stack.push(symbolTable.getVoidType());
    	}
    }

    public void enterFormPars(MicroJavaParser.FormParsContext ctx) {
    	SemanticType returnType = (SemanticType) stack.pop();
    	Token methodName = (Token) stack.pop();
        SymbolMethod sm = symbolTable.addSymbolMethod(methodName.getText(), returnType);
        if (sm == null) {
        	emitErrorMessage(methodName, "Identificador j� declarado: " + methodName.getText());
        	stack.push(null);
        } else {
            stack.push(sm.getSemanticType());
        }
    	symbolTable.pushEnvironment();
    }

    public void exitFormPar(MicroJavaParser.FormParContext ctx) {
    	// Desempilha o tipo do par�metro
    	SemanticType st = (SemanticType) stack.pop();
    	// No topo da pilha est� o tipo do m�todo sendo declarado.
    	// Ele � obtido sem desempilhar, para ser usado em cada par�metro.
    	TypeMethod mt = (TypeMethod) stack.peek();
    	// t ser� o Token contendo o nome do par�metro
    	Token t = ctx.IDENT().getSymbol();
        // Inserir o tipo de par�metro na lista de par�metros do m�todo
    	if (mt != null) {
        	mt.getParams().add(st);
    	}
        // Inserir a declara��o de par�metro na tabela de s�mbolos
        SemanticSymbol novopar = symbolTable.addSymbolVariable(t.getText(), st);
        if (novopar == null) {
        	emitErrorMessage(t, "Identificador j� declarado: " + t.getText());
        }
    }

    public void exitFormPars(MicroJavaParser.FormParsContext ctx) {
    	TypeMethod tm = (TypeMethod) stack.pop();
    }
        
    /**
     * Ao terminar a declara��o de um m�todo, o ambiente � desempilhado
     * da tabela de s�mbolos.
     */
    public void exitMethodDecl(MicroJavaParser.MethodDeclContext ctx) {
    	symbolTable.popEnvironment();
    }
    
	
	
	/**--------------------------------------------------------------
	 * 
	 * Fun��es auxiliares
	 * 
	 *-------------------------------------------------------------*/

	
    private SemanticType searchType(Token t) {
        String name = t.getText();
        SemanticSymbol s = symbolTable.getSymbol(name);
        if (s == null) {
            emitErrorMessage(t, "Identificador n�o declarado: " + name);
            return symbolTable.getNullType();
        }
        if (! s.isClass()) {
          emitErrorMessage(t, "Identificador " + name + " n�o � um tipo v�lido");
            return symbolTable.getNullType();
        }
        return s.getSemanticType();
    }
    
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
    
    public void emitErrorMessage(Token t, String msg) {
    	hasErrors = true;
    	parser.notifyErrorListeners(t, msg, null);
    }
    
    public boolean hasErrors() {
        return hasErrors;
    }

	
}
