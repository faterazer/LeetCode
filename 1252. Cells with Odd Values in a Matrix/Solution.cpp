#include <vector>
using namespace std;

class Solution
{
public:
    int oddCells(int n, int m, vector<vector<int>> &indices)
    {
        vector<bool> r(n, false), c(m, false);
        for (const vector<int> &idx : indices) {
            r[idx[0]] = !r[idx[0]];
            c[idx[1]] = !c[idx[1]];
        }
        int res = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                res += r[i] ^ c[j];
        return res;
    }
};
