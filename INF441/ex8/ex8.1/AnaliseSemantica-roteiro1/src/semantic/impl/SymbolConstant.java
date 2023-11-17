package semantic.impl;

public class SymbolConstant
extends SemanticSymbol
implements semantic.interfaces.SymbolConstant {
	
	private Object value;
	
	public SymbolConstant(String name, semantic.interfaces.SemanticType type, Object value) {
		super(name, type);
		this.value = value;
	}
	
	public boolean isConstant() {
		return true;
	}

	public Object getValue() {
		return value;
	}

}
