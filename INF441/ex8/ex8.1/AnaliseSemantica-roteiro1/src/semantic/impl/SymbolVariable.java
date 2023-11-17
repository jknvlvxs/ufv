package semantic.impl;

import semantic.interfaces.SemanticType;

public class SymbolVariable
extends SemanticSymbol
implements semantic.interfaces.SymbolVariable {

	private int level, offset;
	
	public SymbolVariable(String name,
			SemanticType type, int level, int offset) {
		super(name, type);
		this.level = level;
		this.offset = offset;
	}
	
	public int getLevel() {
		return level;
	}

	public int getOffset() {
		return offset;
	}

	public boolean isVariable() {
		return true;
	}

}
