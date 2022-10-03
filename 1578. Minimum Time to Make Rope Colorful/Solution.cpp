#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime)
    {
        int n = colors.size(), res = 0, max_cost = 0;
        for (int i = 0; i < n; i++) {
            if (i > 0 && colors[i] != colors[i - 1])
                max_cost = 0;
            res += min(neededTime[i], max_cost);
            max_cost = max(max_cost, neededTime[i]);
        }
        return res;
    }
};
