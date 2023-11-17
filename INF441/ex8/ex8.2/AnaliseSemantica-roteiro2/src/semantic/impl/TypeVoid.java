package semantic.impl;

import java.io.PrintStream;

public class TypeVoid
extends TypeScalar
implements semantic.interfaces.TypeVoid {

	public boolean isVoid() {
		return true;
	}

	public void print(PrintStream p) {
		p.print("VOID");
	}

}
