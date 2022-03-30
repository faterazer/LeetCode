#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix_MK1(vector<vector<int>>& matrix, int target)
    {
        int m = matrix.size(), n = matrix[0].size();
        int i = 0, j = n - 1;
        while (i < m && j >= 0) {
            if (matrix[i][0] > target)
                break;
            if (matrix[i][j] < target)
                i += 1;
            else if (matrix[i][j] > target)
                j -= 1;
            else
                return true;
        }
        return false;
    }

    bool searchMatrix_MK2(vector<vector<int>>& matrix, int target)
    {
        auto candidate = upper_bound(matrix.begin(), matrix.end(), target, [](const int& a, const vector<int>& b) {
            return a < b[0];
        });
        if (candidate == matrix.begin())
            return false;
        --candidate;
        return binary_search(candidate->begin(), candidate->end(), target);
    }
};
