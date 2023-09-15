import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.tree.*;
import srcparser.*;

public class Piloto3 {

	public static void testeParser(String fileName) throws Exception {
		// create a CharStream that reads from standard input
		ANTLRInputStream input = new ANTLRFileStream(fileName);
		// create a lexer that feeds off of input CharStream
		MicroJavaLexer lexer = new MicroJavaLexer(input);
		// create a buffer of tokens pulled from the lexer
		CommonTokenStream tokens = new CommonTokenStream(lexer);
		// create a parser that feeds off the tokens buffer
		MicroJavaParser parser = new MicroJavaParser(tokens);
		ParseTree tree = parser.program(); // begin parsing at init rule
		System.out.println(tree.toStringTree(parser)); // print LISP-style tree
	}
		
	
	public static void main(String args[]) throws Exception {
		testeParser("input/teste01.txt");
	}
}
