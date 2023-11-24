
import java.util.Stack;

import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.tree.ParseTreeProperty;
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

    // Associa n�s da �rvore com os tipos identificados na an�lise sem�ntica
    private ParseTreeProperty<SemanticSymbol> ptp;
    
    /**
     * Construtor.
     * @param parser
     * @param symbolTable
     * @param semanticFactory
     */
    public SemanticListener(MicroJavaParser parser, SymbolTable symbolTable,
    		SemanticFactory semanticFactory) {
    	this.parser = parser;
    	this.symbolTable = symbolTable;
    	this.semanticFactory = semanticFactory;
        ptp = new ParseTreeProperty<SemanticSymbol>();
    	symbolTable.pushEnvironment();
    }
    
    
    public ParseTreeProperty<SemanticSymbol> getParseTreeProperty() {
    	return ptp;
    }
    
    
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
    
    public void exitAssign(MicroJavaParser.AssignContext ctx) {
    	SemanticType st2 = (SemanticType) stack.pop();
    	SemanticType st1 = (SemanticType) stack.pop();
    	Token t = ctx.getStart();
    	if (!compatibleTypes(st1, st2)) {
    		emitErrorMessage(t, "Tipos incompat�veis em atribui��o");
    	}
    }
        
    public void exitOneTerm(MicroJavaParser.OneTermContext ctx) {
    	SemanticType st = (SemanticType) stack.peek();
    	if (ctx.op != null && !st.isInteger() && !st.isFloat()) {
    		emitErrorMessage(ctx.op, "Operador s� pode ser aplicado a express�o num�rica");
    	}
    }
    
    public void exitAddSub(MicroJavaParser.AddSubContext ctx) {
    	SemanticType st2 = (SemanticType) stack.pop();
    	SemanticType st1 = (SemanticType) stack.pop();
    	Token t = ctx.getStart();
    	if (!st1.isInteger() && !st1.isFloat() || !st2.isInteger() && !st2.isFloat()) {
    		emitErrorMessage(t, "Operandos devem ser ambos num�ricos");
    	}
    	stack.push(st1);
    }
    
    public void exitMulDiv(MicroJavaParser.MulDivContext ctx) {
    	SemanticType st2 = (SemanticType) stack.pop();
    	SemanticType st1 = (SemanticType) stack.pop();
    	Token t = ctx.getStart();
    	if (!st1.isInteger() && !st1.isFloat() || !st2.isInteger() && !st2.isFloat()) {
    		emitErrorMessage(t, "Operandos devem ser ambos num�ricos");
    	}
    	stack.push(st1);
    }
    
	public void exitNew(MicroJavaParser.NewContext ctx) {
    	if (ctx.expr() != null) {
	    	SemanticType st2 = (SemanticType) stack.pop();
	    	if (!st2.isInteger()) {
	    		emitErrorMessage(ctx.expr().start, "Express�o deve ser inteira");
	    	}
    	}
		Token t = ctx.IDENT().getSymbol();
		SemanticSymbol s = symbolTable.getSymbol(t.getText());
		ptp.put(ctx.IDENT(), s);
	    if (s == null) {
	    	emitErrorMessage(t, "Identificador n�o declarado: " + t.getText());
	    	stack.push(symbolTable.getIntegerType());
	    } else if (!s.isClass()){
	    	emitErrorMessage(t, "Identificador deveria ser classe: " + t.getText());
	    	stack.push(symbolTable.getIntegerType());
	    } else {
	    	SemanticType st = s.getSemanticType();
	    	if (ctx.expr() != null) {
	    		st = semanticFactory.createArrayType(st);
	    	}
	    	stack.push(st);
	    }
	}
    
	public void exitDesigId(MicroJavaParser.DesigIdContext ctx) {
		Token t = ctx.IDENT().getSymbol();
		SemanticSymbol s = symbolTable.getSymbol(t.getText());
		ptp.put(ctx.IDENT(), s);
	    if (s == null) {
	    	emitErrorMessage(t, "Identificador n�o declarado: " + t.getText());
	    	stack.push(symbolTable.getIntegerType());
	    } else {
	    	stack.push(s.getSemanticType());
	    }
	}
	
	public void exitDesigDot(MicroJavaParser.DesigDotContext ctx) {
		SemanticType st = (SemanticType) stack.pop();
		if (!st.isClass()) {
			emitErrorMessage(ctx.getStart(), "Tipo da express�o deve ser uma classe");
			stack.push(symbolTable.getIntegerType());
		} else {
			TypeClass ct = (TypeClass) st;
			Token t = ctx.IDENT().getSymbol();
			SemanticSymbol s = ct.getEnvironment().getSymbol(t.getText());
			ptp.put(ctx.IDENT(), s);
			if (s == null) {
				emitErrorMessage(t, "Atributo n�o encontrado: " + t.getText());
				stack.push(symbolTable.getIntegerType());
			} else {
				stack.push(s.getSemanticType());
			}
		}
	}
	
	public void exitDesigArray(MicroJavaParser.DesigArrayContext ctx) {
		SemanticType st2 = (SemanticType) stack.pop();
		SemanticType st1 = (SemanticType) stack.pop();
		if (!st2.isInteger()) {
			emitErrorMessage(ctx.start, "�ndice de array deve ser express�o inteira");
		}
		if (!st1.isArray()) {
			emitErrorMessage(ctx.start, "Express�o n�o � um array");
			stack.push(symbolTable.getIntegerType());
		} else {
			stack.push(((TypeArray) st1).getInnerType());
		}
	}

	public void exitActPars(MicroJavaParser.ActParsContext ctx) {
		// empilhar o n�mero de par�metros de reais, para saber quantos elementos
		// na pilha s�o associados aos tipos dos par�metros reais
		stack.push(ctx.expr().size());
	}

	public void exitDesig(MicroJavaParser.DesigContext ctx) {
		if (ctx.actPars() != null) {
			processFunCall(ctx.designator(), ctx.actPars());
		}
	}

	public void exitFuncall(MicroJavaParser.FuncallContext ctx) {
		processFunCall(ctx.designator(), ctx.actPars());
		stack.pop(); // desempilha tipo de retorno do m�todo
	}

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
