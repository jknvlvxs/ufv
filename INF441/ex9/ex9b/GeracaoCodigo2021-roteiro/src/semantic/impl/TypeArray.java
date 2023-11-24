package semantic.impl;

import java.io.PrintStream;

public class TypeArray
extends SemanticType
implements semantic.interfaces.TypeArray {

	private semantic.interfaces.SemanticType innerType;
	
	public TypeArray(semantic.interfaces.SemanticType innerType) {
		this.innerType = innerType;
	}
	
	public semantic.interfaces.SemanticType getInnerType() {
		return innerType;
	}
	
	public boolean isArray() {
		return true;
	}

	public void print(PrintStream p) {
		innerType.print(p);
		p.print("[]");
	}

}
