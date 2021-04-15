#include <vector>
using namespace std;

class Solution
{
public:
    int numSpecial(vector<vector<int>> &mat)
    {
        int m = mat.size(), n = mat[0].size(), res = 0;
        vector<int> rows_sum(m, 0), cols_sum(n, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j]) {
                    rows_sum[i]++;
                    cols_sum[j]++;
                }
            }
        }
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (mat[i][j] && rows_sum[i] == 1 && cols_sum[j] == 1)
                    res++;
        return res;
    }
};
