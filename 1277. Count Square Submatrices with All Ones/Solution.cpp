#include <vector>
using namespace std;

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i && j && matrix[i][j])
                    matrix[i][j] += min({matrix[i - 1][j], matrix[i][j - 1], matrix[i - 1][j - 1]});
                ans += matrix[i][j];
            }
        }
        return ans;
    }
};
