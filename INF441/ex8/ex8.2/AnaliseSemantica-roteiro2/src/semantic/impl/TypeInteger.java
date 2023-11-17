package semantic.impl;

import java.io.PrintStream;

public class TypeInteger
extends TypeScalar
implements semantic.interfaces.TypeInteger {

	public boolean isInteger() {
		return true;
	}

	public void print(PrintStream p) {
		p.print("INTEGER");
	}
	
}
