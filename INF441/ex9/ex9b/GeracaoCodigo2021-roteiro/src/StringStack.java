import java.util.ArrayList;
import java.util.List;
import java.util.Stack;


public class StringStack {

	private static String marker = ">>>";
	private Stack<String> stack;
	
	public StringStack() {
		stack = new Stack<String>();
	}
	
	public void pushString(String s) {
		stack.push(s);
	}
	
	public String popString() {
		return stack.pop();
	}
	
	public String peekString() {
		return stack.peek();
	}
	
	public void pushList() {
		stack.push(marker);
	}
	
	public List<String> popList() {
		List<String> list = new ArrayList<String>();
		while (true) {
			String s = stack.pop();
			if (s == marker) break;
			list.add(0, s);
		}
		return list;
	}
	
	public String popList(String separator) {
		String s = stack.pop();
		if (s == marker) return "";
		while (true) {
			String s1 = stack.pop();
			if (s1 == marker) break;
			s = s1 + separator + s;
		}
		return s;
	}
	
	public String toString() {
		String separator = "********************\n";
		String s = separator;
		int k = stack.size();
		for (int i = 1; i <= k; ++i) {
			s += stack.get(k - i) + "\n" + separator;
		}
		return s;
	}

}
