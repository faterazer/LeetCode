#include <stack>
using namespace std;

class MyQueue
{
public:
    /** Initialize your data structure here. */
    MyQueue() = default;

    /** Push element x to the back of queue. */
    void push(int x)
    {
        in_stack.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        int ret = peek();
        out_stack.pop();
        return ret;
    }

    /** Get the front element. */
    int peek()
    {
        if (out_stack.empty()) {
            while (!in_stack.empty()) {
                out_stack.push(in_stack.top());
                in_stack.pop();
            }
        }
        return out_stack.top();
    }

    /** Returns whether the queue is empty. */
    bool empty()
    {
        return in_stack.empty() && out_stack.empty();
    }
private:
    stack<int> in_stack, out_stack;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */