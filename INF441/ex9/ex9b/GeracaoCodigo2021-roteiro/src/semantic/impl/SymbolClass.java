package semantic.impl;

public class SymbolClass
extends SemanticSymbol
implements semantic.interfaces.SymbolClass {
	
	public SymbolClass(String name, semantic.interfaces.SemanticType type) {
		super(name, type);
	}
	
	public boolean isClass() {
		return true;
	}
	
}
