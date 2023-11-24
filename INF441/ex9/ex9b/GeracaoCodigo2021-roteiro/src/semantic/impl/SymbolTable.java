package semantic.impl;

import java.util.Stack;

public class SymbolTable implements semantic.interfaces.SymbolTable {
	
	private boolean debug = false;
	
	private Stack<semantic.interfaces.Environment> stack;
	
	private semantic.interfaces.TypeChar charType;
	private semantic.interfaces.TypeVoid voidType;
	private semantic.interfaces.TypeInteger integerType;
	private semantic.interfaces.TypeFloat floatType;
	private semantic.interfaces.TypeNull nullType;
	private semantic.interfaces.TypeBoolean booleanType;
	
	private semantic.interfaces.TypeMethod printIntType;
	private semantic.interfaces.TypeMethod printFloatType;
	private semantic.interfaces.TypeMethod printCharType;

	/**
	 * Construtor.
	 */
	public SymbolTable() {
		charType = new TypeChar();
		voidType = new TypeVoid();
		integerType = new TypeInteger();
		floatType = new TypeFloat();
		nullType = new TypeNull();
		stack = new Stack<semantic.interfaces.Environment>();
		pushEnvironment();
		addSymbolClass("void", voidType);
		addSymbolClass("int", integerType);
		addSymbolClass("float", floatType);
		addSymbolClass("char", charType);
		addSymbolConstant("null", nullType, 0);
		printIntType = new TypeMethod(voidType);
		printIntType.getParams().add(integerType);
		printIntType.getParams().add(integerType);
		addSymbolMethod("printInt", printIntType);
		printFloatType = new TypeMethod(voidType);
		printFloatType.getParams().add(floatType);
		printFloatType.getParams().add(integerType);
		addSymbolMethod("printFloat", printFloatType);
		printCharType = new TypeMethod(voidType);
		printCharType.getParams().add(charType);
		printCharType.getParams().add(integerType);
		addSymbolMethod("printChar", printCharType);
	}
	
	public void setDebug(boolean b) {
		debug = b;
	}
	
	/**
	 * Empilha ambiente.
	 */
	public void pushEnvironment() {
		if (debug) {
			System.out.println("-- empilha ambiente");
		}
		semantic.interfaces.Environment e = new Environment();
		e.setLevel(stack.size());
		stack.push(e);
	}
	
	/**
	 * Desempilha ambiente.
	 * @return Ambiente desempilhado.
	 */
	public semantic.interfaces.Environment popEnvironment() {
		if (debug) {
			System.out.println("-- desempilha ambiente");
		}
		return stack.pop();
	}

	/**
	 * Procura símbolo, dado identificador.
	 * Procura primeiro nos ambientes dos níveis superiores.
	 * @param name Identificador do símbolo.
	 * @return Símbolo encontrado; ou null, se não encontrar.
	 */
	public semantic.interfaces.SemanticSymbol getSymbol(String name) {
		for (int i = stack.size() - 1; i >= 0; --i) {
			semantic.interfaces.Environment env = stack.get(i);
			semantic.interfaces.SemanticSymbol t = env.getSymbol(name);
			if (t != null) {
				return t;
			}
		}
		return null;
	}

	/**
	 * Adiciona declaração de variável no ambiente corrente.
	 * @param name Nome da variável.
	 * @param type Tipo da variável.
	 * @return Símbolo adicionado; ou null, se o identificador já estiver sendo usado.
	 */
	public semantic.interfaces.SymbolVariable addSymbolVariable(String name, semantic.interfaces.SemanticType type) {
		if (debug) {
			System.out.println("-- adiciona variável " + name);
		}
		semantic.interfaces.Environment env = stack.peek();
		return env.addSymbolVariable(name, type);
	}
	
	/**
	 * Adiciona declaração de método no ambiente corrente. Para facilitar a operação,
	 * deve ser fornecido apenas o tipo de retorno do método. O tipo completo é criado
	 * automaticamente, podendo ser depois alterado para inserir também os tipos
	 * dos parâmteros.
	 * @param name Nome do método.
	 * @param type Tipo de retorno do método (atenção: apenas tipo de retorno,
	 * um objeto de tipo MethodType será criado automaticamente, podendo os tipos
	 * dos parâmetros serem inseridos mais tarde.
	 * @return Símbolo adicionado; ou null, se o identificador já estiver sendo usado.
	 */
	public semantic.interfaces.SymbolMethod addSymbolMethod(String name, semantic.interfaces.SemanticType type) {
		if (debug) {
			System.out.println("-- adiciona método " + name);
		}
		semantic.interfaces.Environment env = stack.peek();
		semantic.interfaces.TypeMethod m = new TypeMethod(type);
		return env.addSymbolMethod(name, m);
	}
	
	/**
	 * Adiciona declaração de classe/tipo no ambiente corrente.
	 * @param name Nome da classe.
	 * @param type Tipo associado.
	 * @return Símbolo adicionado; ou null, se o identificador já estiver sendo usado.
	 */
	public semantic.interfaces.SymbolClass addSymbolClass(String name, semantic.interfaces.TypeClass type) {
		if (debug) {
			System.out.println("-- adiciona classe " + name);
		}
		semantic.interfaces.Environment env = stack.peek();
		return env.addSymbolClass(name, type);
	}
	
	/**
	 * Adiciona declaração de classe/tipo no ambiente corrente,
	 * para os casos em que uma nova classe está sendo criada.
	 * @param name Nome da classe.
	 * @return Símbolo adicionado; ou null, se o identificador já estiver sendo usado.
	 */
	public semantic.interfaces.SymbolClass addSymbolClass(String name) {
		if (debug) {
			System.out.println("-- adiciona classe " + name);
		}
		semantic.interfaces.Environment env = stack.peek();
		semantic.interfaces.TypeClass type = new TypeClass();
		return env.addSymbolClass(name, type);
	}

	public semantic.interfaces.SymbolConstant addSymbolConstant(String name,
			semantic.interfaces.SemanticType type, Object value) {
		if (debug) {
			System.out.println("-- adiciona constante " + name + " com valor " + value);
		}
		semantic.interfaces.Environment env = stack.peek();
		return env.addSymbolConstant(name, type, value);
	}

	/**
	 * Tipo escalar "char".
	 * @return Referência ao tipo escalar, para ser usado em declarações.
	 */
	public semantic.interfaces.TypeChar getCharType() {
		return charType;
	}

	/**
	 * Tipo escalar "void".
	 * @return Referência ao tipo escalar, para ser usado em declarações.
	 */
	public semantic.interfaces.TypeVoid getVoidType() {
		return voidType;
	}

	/**
	 * Tipo escalar "int".
	 * @return Referência ao tipo escalar, para ser usado em declarações.
	 */
	public semantic.interfaces.TypeInteger getIntegerType() {
		return integerType;
	}

	/**
	 * Tipo escalar "float".
	 * @return Referência ao tipo escalar, para ser usado em declarações.
	 */
	public semantic.interfaces.TypeFloat getFloatType() {
		return floatType;
	}

	/**
	 * Tipo escalar "null".
	 * @return Referência ao tipo escalar.
	 */
	public semantic.interfaces.TypeNull getNullType() {
		return nullType;
	}

	/**
	 * Tipo escalar "boolean".
	 * @return Referência ao tipo escalar.
	 */
	public semantic.interfaces.TypeBoolean getBooleanType() {
		return booleanType;
	}
	
}
