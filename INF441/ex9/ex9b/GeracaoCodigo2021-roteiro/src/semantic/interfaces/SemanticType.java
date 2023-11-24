package semantic.interfaces;

import java.io.PrintStream;

public interface SemanticType {

	public boolean isChar();

	public boolean isFloat();

	public boolean isInteger();

	public boolean isVoid();

	public boolean isMethod();

	public boolean isClass();

	public boolean isArray();

	public boolean isNull();

	public boolean isScalar();

	void print(PrintStream p);

}