package semantic.interfaces;

public interface SemanticFactory {

	public TypeArray createTypeArray(SemanticType innerType);

	public TypeClass createTypeClass();

	public TypeMethod createTypeMethod(SemanticType returnType);

	public SymbolTable createSymbolTable();

}