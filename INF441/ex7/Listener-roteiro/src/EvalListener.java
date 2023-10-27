import java.util.HashMap;
import java.util.Map;
import java.util.Stack;

public class EvalListener extends SimpleBaseListener {
	private Map<String, Double> map;
	private Stack<Double> stack;
	
	public EvalListener() {
		map = new HashMap<String, Double>();
		stack = new Stack<Double>();
	}
		
	public void exitReal(SimpleParser.RealContext ctx) {
		stack.push(Double.parseDouble(ctx.REAL_NUMBER().getText()));
	}
	
	public void exitOneTerm(SimpleParser.OneTermContext ctx) {
		if (ctx.op != null) {
			stack.push(-stack.pop());
		}
	}
	
	public void exitAddSub(SimpleParser.AddSubContext ctx) {
		Double d2 = stack.pop();
		Double d1 = stack.pop();
		if (ctx.op.getType() == SimpleParser.ADD) {
			stack.push(d1 + d2);
		} else {
			stack.push(d1 - d2);
		}
	}
	public void exitPrint(SimpleParser.PrintContext ctx) {
		System.out.println(stack.pop());
	}
	
	
	public void exitOneFactor(SimpleParser.OneFactorContext ctx) { }

	public void exitMulDiv(SimpleParser.MulDivContext ctx) {
		Double d2 = stack.pop();
		Double d1 = stack.pop();
		if(ctx.op.getType() == SimpleParser.MUL) {
			stack.push(d1 * d2);
		} else {
			stack.push(d1 / d2);
		}
	}
	
	public void exitId(SimpleParser.IdContext ctx) {
		String ident = ctx.IDENT().getText();
		Double value = map.get(ident);
		
		if(value == null) {
			value = 0.0;
			map.put(ident, value);
		}
		
		stack.push(value);
	}
	
	public void exitAssign(SimpleParser.AssignContext ctx) {
		map.put(ctx.IDENT().getText(), stack.pop());
	}
}