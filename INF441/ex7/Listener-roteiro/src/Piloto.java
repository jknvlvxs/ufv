
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.tree.*;

public class Piloto {
	
	public static void testeParser(String fileName) throws Exception {
		// create a CharStream that reads from standard input
		ANTLRInputStream input = new ANTLRFileStream(fileName);
		// create a lexer that feeds off of input CharStream
		SimpleLexer lexer = new SimpleLexer(input);
		// create a buffer of tokens pulled from the lexer
		CommonTokenStream tokens = new CommonTokenStream(lexer);
		// create a parser that feeds off the tokens buffer
		SimpleParser parser = new SimpleParser(tokens);
		ParseTree tree = parser.program(); // begin parsing at init rule
		System.out.println(tree.toStringTree(parser)); // print LISP-style tree
		
		ParseTreeWalker walker = new ParseTreeWalker();
		EvalListener eval = new EvalListener();
		walker.walk(eval, tree);
	}
		
	
	public static void main(String args[]) throws Exception {
		testeParser("input/teste01.txt");
	}
}
