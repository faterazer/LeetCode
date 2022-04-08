import java.util.Stack;

class Solution {
    public boolean validateStackSequences(int[] pushed, int[] popped) {
        Stack<Integer> stack = new Stack<>();
        int i = 0;
        for (int e : pushed) {
            stack.push(e);
            while (!stack.empty() && stack.peek() == popped[i]) {
                stack.pop();
                i += 1;
            }
        }
        return stack.empty();
    }
}
