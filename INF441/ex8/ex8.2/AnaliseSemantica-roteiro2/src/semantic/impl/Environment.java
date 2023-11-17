
package semantic.impl;

import java.util.Collection;
import java.util.HashMap;

import semantic.interfaces.SemanticSymbol;

public class Environment
implements semantic.interfaces.Environment {
	
	private HashMap<String, semantic.interfaces.SemanticSymbol> map;
	private int level, cont;
	
	public Environment() {
		map = new HashMap<String, semantic.interfaces.SemanticSymbol>();
		cont = 0;
		level = -1;
	}
	
	public void setLevel(int level) {
		this.level = level;
	}
	
	public semantic.interfaces.SymbolVariable addSymbolVariable(
			String name, semantic.interfaces.SemanticType type) {
		if (getSymbol(name)!= null) {
			return null;
		}
		semantic.interfaces.SymbolVariable s = new SymbolVariable(name, type, level, cont);
		++cont;
		map.put(name, s);
		return s;
	}
	
	public semantic.interfaces.SymbolClass addSymbolClass(
			String name, semantic.interfaces.TypeClass type) {
		if (getSymbol(name)!= null) {
			return null;
		}
		semantic.interfaces.SymbolClass s = new SymbolClass(name, type);
		map.put(name, s);
		return s;
	}
	
	public semantic.interfaces.SymbolMethod addSymbolMethod(
			String name, semantic.interfaces.SemanticType type) {
		if (getSymbol(name)!= null) {
			return null;
		}
		semantic.interfaces.SymbolMethod s = new SymbolMethod(name, type);
		map.put(name, s);
		return s;
	}

	public semantic.interfaces.SymbolConstant addSymbolConstant(String name,
			semantic.interfaces.SemanticType type, Object value) {
		if (getSymbol(name)!= null) {
			return null;
		}
		semantic.interfaces.SymbolConstant s = new SymbolConstant(name, type, value);
		map.put(name, s);
		return s;
	}
	
	public semantic.interfaces.SemanticSymbol getSymbol(String name) {
		return map.get(name);
	}
	
	public int numVariaveis() {
		return cont;
	}

	public Collection<SemanticSymbol> getSymbols() {
		return map.values();
	}
	
}