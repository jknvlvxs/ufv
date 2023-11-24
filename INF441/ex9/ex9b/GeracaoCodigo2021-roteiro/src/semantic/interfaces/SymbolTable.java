package semantic.interfaces;

public interface SymbolTable {
	
	/**
	 * Liga / desliga debug da tabela de símbolos.
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
	 * Procura símbolo, dado identificador.
	 * Procura primeiro nos ambientes dos níveis superiores.
	 * @param name Identificador do símbolo.
	 * @return Símbolo encontrado; ou null, se não encontrar.
	 */
	 SemanticSymbol getSymbol(String name);

	/**
	 * Adiciona declaração de variável no ambiente corrente.
	 * @param name Nome da variável.
	 * @param type Tipo da variável.
	 * @return Símbolo adicionado; ou null, se o identificador já estiver sendo usado.
	 */
	 SymbolVariable addSymbolVariable(String name, SemanticType type);
	
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
	 SymbolMethod addSymbolMethod(String name, SemanticType type);
	
	/**
	 * Adiciona declaração de classe/tipo no ambiente corrente.
	 * O tipo semântico é automaticamente criado, e pode ser modificado
	 * mais tarde com o método setEnvironment.
	 * @param name Nome da classe.
	 * @return Símbolo adicionado; ou null, se o identificador já estiver sendo usado.
	 */
	 SymbolClass addSymbolClass(String name);
	 
	/**
	 * Adiciona declaração de constante no ambiente corrente.
	 * @param name Nome da constante.
	 * @param type Tipo associado.
	 * @param value Valor da constante.
	 * @return Símbolo adicionado; ou null, se o identificador já estiver sendo usado.
	 */
	 SymbolConstant addSymbolConstant(String name, SemanticType type, Object value);

	/**
	 * Tipo escalar "char".
	 * @return Referência ao tipo escalar, para ser usado em declarações.
	 */
	 TypeChar getCharType();

	/**
	 * Tipo escalar "void".
	 * @return Referência ao tipo escalar, para ser usado em declarações.
	 */
	 TypeVoid getVoidType();

	/**
	 * Tipo escalar "int".
	 * @return Referência ao tipo escalar, para ser usado em declarações.
	 */
	 TypeInteger getIntegerType();

	/**
	 * Tipo escalar "float".
	 * @return Referência ao tipo escalar, para ser usado em declarações.
	 */
	 TypeFloat getFloatType();

	/**
	 * Tipo escalar "null".
	 * @return Referência ao tipo escalar.
	 */
	 TypeNull getNullType();

	/**
	 * Tipo escalar "boolean".
	 * @return Referência ao tipo escalar.
	 */
	 TypeBoolean getBooleanType();
	
}
