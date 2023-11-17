package semantic.impl;

public class SymbolMethod
extends SemanticSymbol
implements semantic.interfaces.SymbolMethod {
	
	public SymbolMethod(String name, semantic.interfaces.SemanticType type) {
		super(name, type);
	}

	public boolean isMethod() {
		return true;
	}

}
