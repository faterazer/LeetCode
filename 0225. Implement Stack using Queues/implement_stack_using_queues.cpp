#include <queue>
using namespace std;

class MyStack
{
public:
    /** Initialize your data structure here. */
    MyStack() = default;

    /** Push element x onto stack. */
    void push(int x)
    {
        Q.push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop()
    {
        int top = Q.back();
        size_t n = Q.size() - 1;
        for (size_t i = 0; i < n; i++) {
            Q.push(Q.front());
            Q.pop();
        }
        Q.pop();
        return top;
    }

    /** Get the top element. */
    int top()
    {
        return Q.back();
    }

    /** Returns whether the stack is empty. */
    bool empty()
    {
        return Q.empty();
    }
private:
    queue<int> Q;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
