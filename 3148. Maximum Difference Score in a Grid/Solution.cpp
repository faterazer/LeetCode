#include <vector>
using namespace std;

class Solution {
public:
    int maxScore(vector<vector<int>>& grid)
    {
        int n = grid[0].size(), res = INT_MIN;
        vector<int> f(n, INT_MAX);
        for (const vector<int>& row : grid) {
            int min_val = INT_MAX;
            for (int i = 0; i < n; i++) {
                res = max(res, row[i] - min(f[i], min_val));
                min_val = min(min_val, row[i]);
                f[i] = min(f[i], min_val);
            }
        }
        return res;
    }
};
