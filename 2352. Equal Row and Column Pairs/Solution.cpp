#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid)
    {
        map<vector<int>, int> cnt;
        for (const vector<int>& row : grid)
            cnt[row]++;

        int res = 0, n = grid.size();
        for (int j = 0; j < n; j++) {
            vector<int> buff;
            for (int i = 0; i < n; i++)
                buff.emplace_back(grid[i][j]);
            res += cnt[buff];
        }
        return res;
    }
};
