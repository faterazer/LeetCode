#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target)
    {
        int min_base_cost = *min_element(baseCosts.begin(), baseCosts.end());
        if (min_base_cost > target)
            return min_base_cost;

        int res = target - min_base_cost;
        vector<int> dp(target + 1, 0);
        for (const int& bc : baseCosts) {
            if (bc <= target)
                dp[bc] = 1;
            else
                res = min(res, bc - target);
        }

        for (const int& cost : toppingCosts) {
            for (int count = 0; count < 2; count++) {
                for (int i = target; i; i--) {
                    if (dp[i]) {
                        if (i + cost > target)
                            res = min(res, i + cost - target);
                        else
                            dp[i + cost] = 1;
                    }
                }
            }
        }
        for (int i = target; i >= target - res; i--)
            if (dp[i])
                return i;
        return target + res;
    }
};
