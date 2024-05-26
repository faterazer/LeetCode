#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k)
    {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> res;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] ^= i > 0 ? matrix[i - 1][j] : 0;
                matrix[i][j] ^= j > 0 ? matrix[i][j - 1] : 0;
                matrix[i][j] ^= i > 0 && j > 0 ? matrix[i - 1][j - 1] : 0;
                res.emplace_back(matrix[i][j]);
            }
        }
        ranges::nth_element(res, res.end() - k);
        return res[res.size() - k];
    }
};
