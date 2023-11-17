package semantic.impl;

import java.io.PrintStream;

public class TypeNull
extends SemanticType
implements semantic.interfaces.TypeNull {

	public boolean isNull() {
		return true;
	}

	public void print(PrintStream p) {
		p.print("NULL");
	}

}
