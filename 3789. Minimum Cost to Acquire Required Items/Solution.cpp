#include <algorithm>
using namespace std;

class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2)
    {
        int common_need = min(need1, need2);
        long long common_cost = 1LL * common_need * min(cost1 + cost2, costBoth);
        long long remain_cost1 = 1LL * (need1 - common_need) * min(cost1, costBoth);
        long long remain_cots2 = 1LL * (need2 - common_need) * min(cost2, costBoth);
        return common_cost + remain_cost1 + remain_cots2;
    }
};
