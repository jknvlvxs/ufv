package semantic.impl;

import java.io.PrintStream;
import java.util.Collection;

import semantic.interfaces.SemanticSymbol;

public class TypeClass
extends SemanticType
implements semantic.interfaces.TypeClass {

	private semantic.interfaces.Environment env;
	
	public TypeClass() {
		env = new Environment();
	}

	public semantic.interfaces.Environment getEnvironment() {
		return env;
	}
	
	public void setEnvironment(semantic.interfaces.Environment env) {
		this.env = env;
	}
	
	public boolean isClass() {
		return true;
	}
	
	public boolean isScalar() {
		return false;
	}

	public void print(PrintStream p) {
		p.print("CLASSE { ");
		Collection<SemanticSymbol> c = ((semantic.impl.Environment) env).getSymbols();
		for (SemanticSymbol s : c) {
			p.print(s.getName() + ":");
			s.getSemanticType().print(p);
			p.print(" ");
		}
		p.print("}");
	}

}
