package semantic.impl;

import java.io.PrintStream;

public class TypeChar
extends TypeScalar
implements semantic.interfaces.TypeChar {

	public boolean isChar() {
		return true;
	}

	public void print(PrintStream p) {
		p.print("CHAR");
	}

}
