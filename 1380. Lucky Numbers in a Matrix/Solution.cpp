#include <climits>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> luckyNumbers(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> rows(m, INT_MAX);
        vector<int> cols(n, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rows[i] = min(rows[i], matrix[i][j]);
                cols[j] = max(cols[j], matrix[i][j]);
            }
        }
        vector<int> res;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (rows[i] == cols[j])
                    res.emplace_back(rows[i]);
        return res;
    }
};
