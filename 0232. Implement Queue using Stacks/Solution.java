import java.util.Stack;

class MyQueue {
    private final Stack<Integer> inStack = new Stack<>();
    private final Stack<Integer> outStack = new Stack<>();

    /** Initialize your data structure here. */
    public MyQueue() {

    }

    /** Push element x to the back of queue. */
    public void push(int x) {
        inStack.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    public int pop() {
        int res = peek();
        outStack.pop();
        return res;
    }

    /** Get the front element. */
    public int peek() {
        if (outStack.empty()) {
            while (!inStack.empty()) {
                outStack.push(inStack.pop());
            }
        }
        return outStack.peek();
    }

    /** Returns whether the queue is empty. */
    public boolean empty() {
        return inStack.empty() && outStack.empty();
    }
}
