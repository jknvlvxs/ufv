package semantic.interfaces;

public interface SymbolTable {
	
	/**
	 * Liga / desliga debug da tabela de s�mbolos.
	 * @param b
	 */
	 void setDebug(boolean b);
	
	/**
	 * Empilha ambiente.
	 */
	 void pushEnvironment();
	
	/**
	 * Desempilha ambiente.
	 * @return Ambiente desempilhado.
	 */
	 Environment popEnvironment();

	/**
	 * Procura s�mbolo, dado identificador.
	 * Procura primeiro nos ambientes dos n�veis superiores.
	 * @param name Identificador do s�mbolo.
	 * @return S�mbolo encontrado; ou null, se n�o encontrar.
	 */
	 SemanticSymbol getSymbol(String name);

	/**
	 * Adiciona declara��o de vari�vel no ambiente corrente.
	 * @param name Nome da vari�vel.
	 * @param type Tipo da vari�vel.
	 * @return S�mbolo adicionado; ou null, se o identificador j� estiver sendo usado.
	 */
	 SymbolVariable addSymbolVariable(String name, SemanticType type);
	
	/**
	 * Adiciona declara��o de m�todo no ambiente corrente. Para facilitar a opera��o,
	 * deve ser fornecido apenas o tipo de retorno do m�todo. O tipo completo � criado
	 * automaticamente, podendo ser depois alterado para inserir tamb�m os tipos
	 * dos par�mteros.
	 * @param name Nome do m�todo.
	 * @param type Tipo de retorno do m�todo (aten��o: apenas tipo de retorno,
	 * um objeto de tipo MethodType ser� criado automaticamente, podendo os tipos
	 * dos par�metros serem inseridos mais tarde.
	 * @return S�mbolo adicionado; ou null, se o identificador j� estiver sendo usado.
	 */
	 SymbolMethod addSymbolMethod(String name, SemanticType type);
	
	/**
	 * Adiciona declara��o de classe/tipo no ambiente corrente.
	 * O tipo sem�ntico � automaticamente criado, e pode ser modificado
	 * mais tarde com o m�todo setEnvironment.
	 * @param name Nome da classe.
	 * @return S�mbolo adicionado; ou null, se o identificador j� estiver sendo usado.
	 */
	 SymbolClass addSymbolClass(String name);
	 
	/**
	 * Adiciona declara��o de constante no ambiente corrente.
	 * @param name Nome da constante.
	 * @param type Tipo associado.
	 * @param value Valor da constante.
	 * @return S�mbolo adicionado; ou null, se o identificador j� estiver sendo usado.
	 */
	 SymbolConstant addSymbolConstant(String name, SemanticType type, Object value);

	/**
	 * Tipo escalar "char".
	 * @return Refer�ncia ao tipo escalar, para ser usado em declara��es.
	 */
	 TypeChar getCharType();

	/**
	 * Tipo escalar "void".
	 * @return Refer�ncia ao tipo escalar, para ser usado em declara��es.
	 */
	 TypeVoid getVoidType();

	/**
	 * Tipo escalar "int".
	 * @return Refer�ncia ao tipo escalar, para ser usado em declara��es.
	 */
	 TypeInteger getIntegerType();

	/**
	 * Tipo escalar "float".
	 * @return Refer�ncia ao tipo escalar, para ser usado em declara��es.
	 */
	 TypeFloat getFloatType();

	/**
	 * Tipo escalar "null".
	 * @return Refer�ncia ao tipo escalar.
	 */
	 TypeNull getNullType();

	/**
	 * Tipo escalar "boolean".
	 * @return Refer�ncia ao tipo escalar.
	 */
	 TypeBoolean getBooleanType();
	
}
