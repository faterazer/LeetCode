#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> finalPrices(vector<int> &prices)
    {
        stack<int> stk;
        for (size_t i = 0; i < prices.size(); i++) {
            while (!stk.empty() && prices[stk.top()] >= prices[i]) {
                prices[stk.top()] -= prices[i];
                stk.pop();
            }
            stk.emplace(i);
        }
        return prices;
    }
};
