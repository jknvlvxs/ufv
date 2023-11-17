
package semantic.interfaces;

public interface Environment {
	
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
	 * Adiciona declara��o de m�todo no ambiente corrente.
	 * @param name Nome do m�todo.
	 * @param type Tipo de retorno do m�todo.
	 * @return S�mbolo adicionado; ou null, se o identificador j� estiver sendo usado.
	 */
	SymbolMethod addSymbolMethod(String name, SemanticType type);
	
	/**
	 * Adiciona declara��o de classe/tipo no ambiente corrente.
	 * @param name Nome da classe.
	 * @param type Tipo associado.
	 * @return S�mbolo adicionado; ou null, se o identificador j� estiver sendo usado.
	 */
	SymbolClass addSymbolClass(String name, TypeClass type);
		
	/**
	 * Adiciona declara��o de constante no ambiente corrente.
	 * @param name Nome da constante.
	 * @param type Tipo associado.
	 * @param value Valor da constante.
	 * @return S�mbolo adicionado; ou null, se o identificador j� estiver sendo usado.
	 */
	SymbolConstant addSymbolConstant(String name, SemanticType type, Object value);
	
	/**
	 * Define o n�vel do ambiente na pilha.
	 * @param level N�vel do ambiente.
	 */
	void setLevel(int level);

	/**
	 * Retorna o n�mero de vari�veis armazenadas neste ambiente.
	 * @return N�mero de vari�veis do ambiente.
	 */
	int numVariaveis();
	
	
}
