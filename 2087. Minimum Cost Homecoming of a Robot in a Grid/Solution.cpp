#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts)
    {
        int r0 = startPos[0], c0 = startPos[1];
        int r1 = homePos[0], c1 = homePos[1];
        int result = -rowCosts[r0] - colCosts[c0];
        result += reduce(rowCosts.begin() + min(r0, r1), rowCosts.begin() + max(r0, r1) + 1, 0);
        result += reduce(colCosts.begin() + min(c0, c1), colCosts.begin() + max(c0, c1) + 1, 0);
        return result;
    }
};
