#include <vector>
using namespace std;

class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k)
    {
        long long total = 0, s = 0;
        for (int i = 0; i < k / 2; ++i) {
            total += prices[i] * strategy[i];
            s -= prices[i] * strategy[i];
        }
        for (int i = k / 2; i < k; ++i) {
            total += prices[i] * strategy[i];
            s += prices[i] * (1 - strategy[i]);
        }

        long long max_s = max(0LL, s);
        for (size_t i = k; i < prices.size(); ++i) {
            total += prices[i] * strategy[i];
            s += prices[i] * (1 - strategy[i]) - prices[i - k / 2] + prices[i - k] * strategy[i - k];
            max_s = max(max_s, s);
        }
        return total + max_s;
    }
};
