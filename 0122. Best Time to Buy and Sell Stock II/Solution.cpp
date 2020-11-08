#include <vector>
using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices);
};

int Solution::maxProfit(vector<int> &prices)
{
    int sum = 0;
    for (size_t i = 1; i < prices.size(); i++)
        if (prices[i] - prices[i-1] > 0)
            sum += prices[i] - prices[i-1];
    return sum;
}
