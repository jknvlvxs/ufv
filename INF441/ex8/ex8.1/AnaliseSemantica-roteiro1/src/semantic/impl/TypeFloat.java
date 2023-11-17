package semantic.impl;

import java.io.PrintStream;

public class TypeFloat
extends TypeScalar 
implements semantic.interfaces.TypeFloat {

	public boolean isFloat() {
		return true;
	}

	public void print(PrintStream p) {
		p.print("FLOAT");
	}

}
