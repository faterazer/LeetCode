#include <stack>
using namespace std;

class StockSpanner {
public:
    StockSpanner()
    {
        stk.emplace(INT_MAX, 0);
        cnt = 1;
    }

    int next(int price)
    {
        while (price >= stk.top().first)
            stk.pop();
        int res = cnt - stk.top().second;
        stk.emplace(price, cnt++);
        return res;
    }

private:
    stack<pair<int, int>> stk;
    int cnt;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
