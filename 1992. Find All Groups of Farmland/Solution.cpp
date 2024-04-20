#include <functional>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land)
    {
        int m = land.size(), n = land[0].size();
        vector<vector<int>> res;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (land[i][j] != 1)
                    continue;

                int r = i, c = j;
                while (r + 1 < m && land[r + 1][j] == 1)
                    r++;
                while (c + 1 < n && land[i][c + 1] == 1)
                    c++;
                res.push_back({ i, j, r, c });

                for (int x = i; x <= r; x++)
                    for (int y = j; y <= c; y++)
                        land[x][y] = 2;
            }
        }
        return res;
    }
};
