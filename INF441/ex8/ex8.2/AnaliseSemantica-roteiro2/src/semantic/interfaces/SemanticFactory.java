package semantic.interfaces;

public interface SemanticFactory {

	public TypeArray createArrayType(SemanticType innerType);

	public TypeClass createClassType();

	public TypeMethod createMethodType(SemanticType returnType);

	public SymbolTable createSymbolTable();

}