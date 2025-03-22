#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat)
    {
        int idx = 0, max_ones = 0;
        for (size_t i = 0; i < mat.size(); ++i) {
            int row_sum = reduce(mat[i].begin(), mat[i].end());
            if (row_sum > max_ones) {
                max_ones = row_sum;
                idx = i;
            }
        }
        return {idx, max_ones};
    }
};
