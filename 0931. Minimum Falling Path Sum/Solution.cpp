#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix)
    {
        int n = matrix.size();
        vector<int> cur(matrix[0]);
        for (int i = 1; i < n; i++) {
            vector<int> pre(cur);
            for (int j = 0; j < n; j++)
                cur[j] = matrix[i][j] + min(pre[j], min(j == 0 ? INT_MAX : pre[j - 1], j == n - 1 ? INT_MAX : pre[j + 1]));
        }
        return *min_element(cur.begin(), cur.end());
    }
};
