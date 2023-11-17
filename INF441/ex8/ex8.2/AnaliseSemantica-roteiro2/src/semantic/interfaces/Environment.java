
package semantic.interfaces;

public interface Environment {
	
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
	 * Adiciona declaração de método no ambiente corrente.
	 * @param name Nome do método.
	 * @param type Tipo de retorno do método.
	 * @return Símbolo adicionado; ou null, se o identificador já estiver sendo usado.
	 */
	SymbolMethod addSymbolMethod(String name, SemanticType type);
	
	/**
	 * Adiciona declaração de classe/tipo no ambiente corrente.
	 * @param name Nome da classe.
	 * @param type Tipo associado.
	 * @return Símbolo adicionado; ou null, se o identificador já estiver sendo usado.
	 */
	SymbolClass addSymbolClass(String name, TypeClass type);
		
	/**
	 * Adiciona declaração de constante no ambiente corrente.
	 * @param name Nome da constante.
	 * @param type Tipo associado.
	 * @param value Valor da constante.
	 * @return Símbolo adicionado; ou null, se o identificador já estiver sendo usado.
	 */
	SymbolConstant addSymbolConstant(String name, SemanticType type, Object value);
	
	/**
	 * Define o nível do ambiente na pilha.
	 * @param level Nível do ambiente.
	 */
	void setLevel(int level);

	/**
	 * Retorna o número de variáveis armazenadas neste ambiente.
	 * @return Número de variáveis do ambiente.
	 */
	int numVariaveis();
	
	
}
