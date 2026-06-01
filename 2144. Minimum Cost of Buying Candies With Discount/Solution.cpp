#include <algorithm>
#include <numeric>
#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& cost)
    {
        ranges::sort(cost, greater<>{});
        int result = reduce(cost.begin(), cost.end(), 0);
        for (size_t i = 2; i < cost.size(); i += 3)
            result -= cost[i];
        return result;
    }
};
