#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid)
    {
        int n = grid[0].size();
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            int j = i;
            for (const vector<int>& row : grid) {
                int k = j;
                j += row[j];
                if (j < 0 || j >= n || row[k] != row[j]) {
                    j = -1;
                    break;
                }
            }
            res[i] = j;
        }
        return res;
    }
};
