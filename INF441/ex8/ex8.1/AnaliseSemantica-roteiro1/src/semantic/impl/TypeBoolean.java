package semantic.impl;

import java.io.PrintStream;

public class TypeBoolean
extends TypeScalar
implements semantic.interfaces.TypeBoolean {

	public boolean isBoolean() {
		return true;
	}

	public void print(PrintStream p) {
		p.print("BOOLEAN");
	}
}
