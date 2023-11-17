package semantic.impl;

public class SemanticSymbol
implements semantic.interfaces.SemanticSymbol {

	private String name;
	private semantic.interfaces.SemanticType type;
	
	public SemanticSymbol(String name, semantic.interfaces.SemanticType type) {
		this.name = name;
		this.type = type;
	}
	
	public String getName() {
		return name;
	}
	
	public semantic.interfaces.SemanticType getSemanticType() {
		return type;
	}

	public void setSemanticType(semantic.interfaces.SemanticType st) {
		type = st;
	}

	public boolean isConstant() {
		return false;
	}
	
	public boolean isVariable() {
		return false;
	}
	
	public boolean isClass() {
		return false;
	}
	
	public boolean isMethod() {
		return false;
	}

}
