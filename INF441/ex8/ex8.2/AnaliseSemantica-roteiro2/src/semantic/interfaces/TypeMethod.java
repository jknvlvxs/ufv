package semantic.interfaces;

import java.util.List;

public interface TypeMethod
extends SemanticType {
	
	public List<SemanticType> getParams();

	public SemanticType getReturnType();

}
