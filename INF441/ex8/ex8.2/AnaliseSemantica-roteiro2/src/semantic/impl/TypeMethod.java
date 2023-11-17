package semantic.impl;

import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;

public class TypeMethod
extends SemanticType
implements semantic.interfaces.TypeMethod {

	private semantic.interfaces.SemanticType returnType;
	private List<semantic.interfaces.SemanticType> params;
	
	public TypeMethod(semantic.interfaces.SemanticType returnType) {
		this.returnType = returnType;
		this.params = new ArrayList<semantic.interfaces.SemanticType>();
	}
	
	public TypeMethod(semantic.interfaces.SemanticType returnType,
			List<semantic.interfaces.SemanticType> params) {
		this.returnType = returnType;
		this.params = params;
	}

	public List<semantic.interfaces.SemanticType> getParams() {
		return params;
	}

	public semantic.interfaces.SemanticType getReturnType() {
		return returnType;
	}
	
	public boolean isMethod() {
		return true;
	}

	public void print(PrintStream p) {
		p.print("METODO - retorna: ");
		if (getReturnType() != null) {
			getReturnType().print(p);
		} else {
			System.out.println("ERRO - FALTA O TIPO DE RETORNO");
		}
		p.print(" - parametros: ");
		for (semantic.interfaces.SemanticType t : getParams()) {
			t.print(p);
			p.print(" ");
		}
	}

}
