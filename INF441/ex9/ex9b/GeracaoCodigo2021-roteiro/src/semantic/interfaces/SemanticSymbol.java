package semantic.interfaces;

public interface SemanticSymbol {

	String getName();
	
	SemanticType getSemanticType();
	
	void setSemanticType(SemanticType st);
	
	boolean isConstant();
	
	boolean isVariable();
	
	boolean isClass();
	
	boolean isMethod();
	
}
