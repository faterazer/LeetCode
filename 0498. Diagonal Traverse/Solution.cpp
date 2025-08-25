#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat)
    {
        int m = mat.size(), n = mat[0].size();
        vector<int> ans;
        ans.reserve(m + n);
        for (int k = 0; k <= m + n; ++k) {
            int min_j = max(k - m + 1, 0), max_j = min(k, n - 1);
            if (k % 2 == 0) {
                for (int j = min_j; j <= max_j; ++j)
                    ans.emplace_back(mat[k - j][j]);
            } else {
                for (int j = max_j; j >= min_j; --j)
                    ans.emplace_back(mat[k - j][j]);
            }
        }
        return ans;
    }
};
