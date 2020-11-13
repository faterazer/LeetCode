#include <vector>
using namespace std;

class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int a = cost[0], b = cost[1], tmp;
        for (size_t i = 2; i < cost.size(); i++) {
            tmp = b;
            b = min(a, b) + cost[i];
            a = tmp;
        }
        return min(a, b);
    }
};
