package semantic.impl;

public abstract class SemanticType implements semantic.interfaces.SemanticType {

	public boolean isChar() {
		return false;
	}

	public boolean isFloat() {
		return false;
	}

	public boolean isInteger() {
		return false;
	}

	public boolean isVoid() {
		return false;
	}
	
	public boolean isMethod() {
		return false;
	}
	
	public boolean isClass() {
		return false;
	}
	
	public boolean isArray() {
		return false;
	}
	
	public boolean isNull() {
		return false;
	}
	
	public boolean isScalar() {
		return false;
	}
	
}
