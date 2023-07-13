#include <vector>
using namespace std;

class Solution {
public:
    int minCostII(vector<vector<int>>& costs)
    {
        int n = costs.size(), k = costs[0].size();
        int idx1 = -1, idx2 = -1;
        for (int i = 0; i < n; i++) {
            int last1 = idx1, last2 = idx2;
            idx1 = idx2 = -1;
            for (int j = 0; j < k; j++) {
                if (j != last1)
                    costs[i][j] += last1 < 0 ? 0 : costs[i - 1][last1];
                else
                    costs[i][j] += last2 < 0 ? 0 : costs[i - 1][last2];

                if (idx1 < 0 || costs[i][j] < costs[i][idx1]) {
                    idx2 = idx1;
                    idx1 = j;
                } else if (idx2 < 0 || costs[i][j] < costs[i][idx2])
                    idx2 = j;
            }
        }
        return costs.back()[idx1];
    }
};
