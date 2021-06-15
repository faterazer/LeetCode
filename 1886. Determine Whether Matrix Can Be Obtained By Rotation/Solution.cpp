#include <vector>
using namespace std;

class Solution
{
public:
    bool findRotation(vector<vector<int>> &mat, vector<vector<int>> &target)
    {
        bool r[4];
        memset(r, true, sizeof(r));
        int m = mat.size(), n = mat[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] != target[i][j])
                    r[0] = false;
                if (mat[i][j] != target[j][n - i - 1])
                    r[1] = false;
                if (mat[i][j] != target[n - i - 1][n - 1 - j])
                    r[2] = false;
                if (mat[i][j] != target[n - j - 1][i])
                    r[3] = false;
            }
        }
        return r[0] || r[1] || r[2] || r[3];
    }
};
