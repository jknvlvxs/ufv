
import java.util.List;

import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.tree.*;

import semantic.interfaces.SemanticFactory;
import semantic.interfaces.SymbolTable;

public class Piloto {
	
	public static boolean hasSyntaxError = false;

	public static void testeinput(String fileName) throws Exception {
		// create a CharStream that reads from standard input
		ANTLRInputStream input = new ANTLRFileStream(fileName);
		// create a lexer that feeds off of input CharStream
		MicroJavaLexer lexer = new MicroJavaLexer(input);
		// create a buffer of tokens pulled from the lexer
		CommonTokenStream tokens = new CommonTokenStream(lexer);
		// create a parser that feeds off the tokens buffer
		MicroJavaParser parser = new MicroJavaParser(tokens);
		parser.addErrorListener(new MyErrorListener());
		ParseTree tree = parser.program(); // begin parsing at init rule
		if (hasSyntaxError) {
			return;
		}
		
		SemanticFactory semanticFactory = new semantic.impl.Factory();
		SymbolTable symbolTable = semanticFactory.createSymbolTable();
		symbolTable.setDebug(true);
		ParseTreeWalker walker = new ParseTreeWalker(); // create standard walker
		SemanticListener semantics = new SemanticListener(parser, symbolTable, semanticFactory);
		walker.walk(semantics, tree); // initiate walk of tree with listener
		if (!semantics.hasErrors()) {
			System.out.println("Nenhum erro de semântica detectado");
		}
	}

	
	public static void main(String args[]) throws Exception {
		testeinput("input/teste01.txt");
	}
	
}

class MyErrorListener extends BaseErrorListener {
	public void syntaxError(Recognizer<?, ?> recognizer,
			Object offendingSymbol,
			int line, int charPositionInLine,
			String msg,
			RecognitionException e)
	{
		Piloto.hasSyntaxError = true;
	}
}
