import java.util.ArrayDeque;
import java.util.Deque;

class MinStack {
    Deque<Integer> stack = new ArrayDeque<>();
    Deque<Integer> minStack = new ArrayDeque<>();

    public MinStack() {

    }

    public void push(int val) {
        stack.addLast(val);
        if (minStack.isEmpty() || val <= minStack.getLast()) {
            minStack.addLast(val);
        }
    }

    public void pop() {
        int val = stack.removeLast();
        if (val == minStack.getLast()) {
            minStack.removeLast();
        }
    }

    public int top() {
        return stack.getLast();
    }

    public int getMin() {
        return minStack.getLast();
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
