package semantic.impl;

public class Factory implements semantic.interfaces.SemanticFactory {
	
	public semantic.interfaces.TypeArray createArrayType(semantic.interfaces.SemanticType innerType) {
		return new TypeArray(innerType);
	}
	
	public semantic.interfaces.TypeClass createClassType() {
		return new TypeClass();
	}
	
	public semantic.interfaces.TypeMethod createMethodType(
			semantic.interfaces.SemanticType returnType) {
		return new TypeMethod(returnType);
	}

	public semantic.interfaces.SymbolTable createSymbolTable() {
		return new SymbolTable();
	}

}
