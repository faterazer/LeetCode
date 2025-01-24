#include <deque>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumCoins(vector<int>& prices)
    {
        vector<int> f(prices.size() + 1);
        f[0] = 0;
        deque<int> mono_queue;
        for (size_t i = 1; i <= prices.size(); ++i) {
            while (!mono_queue.empty() && mono_queue.front() < (i + 1) / 2)
                mono_queue.pop_front();
            while (!mono_queue.empty() && f[mono_queue.back() - 1] + prices[mono_queue.back() - 1] >= f[i - 1] + prices[i - 1])
                mono_queue.pop_back();
            mono_queue.emplace_back(i);
            f[i] = f[mono_queue.front() - 1] + prices[mono_queue.front() - 1];
        }
        return f.back();
    }
};
