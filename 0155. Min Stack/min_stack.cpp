#include <list>
using namespace std;


class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        data_stk.emplace_front(x);
        if (min_stk.empty() || x <= min_stk.front())
            min_stk.emplace_front(x);
    }
    
    void pop() {
        if (min_stk.front() == data_stk.front())
            min_stk.pop_front();
        data_stk.pop_front();
    }
    
    int top() {
        return data_stk.front();
    }
    
    int getMin() {
        return min_stk.front();
    }
private:
    list<int> data_stk;
    list<int> min_stk;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
