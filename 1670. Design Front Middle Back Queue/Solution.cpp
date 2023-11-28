#include <deque>
using namespace std;

class FrontMiddleBackQueue {
public:
    FrontMiddleBackQueue()
    {
    }

    void pushFront(int val)
    {
        q1.emplace_front(val);
        if (q1.size() > q2.size()) {
            q2.emplace_front(q1.back());
            q1.pop_back();
        }
    }

    void pushMiddle(int val)
    {
        if (q1.size() == q2.size())
            q2.emplace_front(val);
        else
            q1.emplace_back(val);
    }

    void pushBack(int val)
    {
        q2.emplace_back(val);
        if (q2.size() - q1.size() == 2) {
            q1.emplace_back(q2.front());
            q2.pop_front();
        }
    }

    int popFront()
    {
        if (q1.empty() && q2.empty())
            return -1;
        else if (q1.empty()) {
            int res = q2.front();
            q2.pop_front();
            return res;
        }
        int res = q1.front();
        q1.pop_front();
        if (q2.size() - q1.size() == 2) {
            q1.emplace_back(q2.front());
            q2.pop_front();
        }
        return res;
    }

    int popMiddle()
    {
        if (q1.empty() && q2.empty())
            return -1;
        if (q1.size() == q2.size()) {
            int res = q1.back();
            q1.pop_back();
            return res;
        } else {
            int res = q2.front();
            q2.pop_front();
            return res;
        }
    }

    int popBack()
    {
        if (q1.empty() && q2.empty())
            return -1;
        if (q2.empty()) {
            int res = q1.back();
            q1.pop_back();
            return res;
        }
        int res = q2.back();
        q2.pop_back();
        if (q1.size() - q2.size() == 1) {
            q2.emplace_front(q1.back());
            q1.pop_back();
        }
        return res;
    }

private:
    deque<int> q1, q2;
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */
