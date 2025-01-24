#include <deque>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumCoins(vector<int>& prices)
    {
        if (prices.size() < 3)
            return prices[0];
        vector<int> f(prices.size() + 1);
        deque<int> mono_deque;
        f[1] = f[2] = prices[0];
        mono_deque.emplace_back(2);
        for (size_t i = 3; i <= prices.size(); ++i) {
            while (!mono_deque.empty() && mono_deque.front() < (i + 1) / 2)
                mono_deque.pop_front();
            while (!mono_deque.empty() && f[mono_deque.back() - 1] + prices[mono_deque.back() - 1] >= f[i - 1] + prices[i - 1])
                mono_deque.pop_back();
            mono_deque.emplace_back(i);
            f[i] = f[mono_deque.front() - 1] + prices[mono_deque.front() - 1];
        }
        return f.back();
    }
};
