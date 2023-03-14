#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum)
    {
        int m = rowSum.size(), n = colSum.size(), i = 0, j = 0;
        vector<vector<int>> res(m, vector<int>(n, 0));
        while (i < m && j < n) {
            int t = res[i][j] = min(rowSum[i], colSum[j]);
            if ((rowSum[i] -= t) == 0)
                i++;
            if ((colSum[j] -= t) == 0)
                j++;
        }
        return res;
    }
};
