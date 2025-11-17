#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries)
    {
        vector<vector<int>> diff(n + 2, vector<int>(n + 2));
        for (const vector<int>& query : queries) {
            int r1 = query[0], c1 = query[1], r2 = query[2], c2 = query[3];
            ++diff[r1 + 1][c1 + 1];
            --diff[r1 + 1][c2 + 2];
            --diff[r2 + 2][c1 + 1];
            ++diff[r2 + 2][c2 + 2];
        }

        vector<vector<int>> result(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                diff[i + 1][j + 1] += diff[i + 1][j] + diff[i][j + 1] - diff[i][j];
                result[i][j] = diff[i + 1][j + 1];
            }
        }
        return result;
    }
};
