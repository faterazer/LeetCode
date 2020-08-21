#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &nums, int r, int c)
    {
        int m = nums.size(), n = nums[0].size();
        if (m * n != r * c)
            return nums;
        vector<vector<int>> matrix(r, vector<int>(c));
        for (int i = 0; i < m * n; i++)
            matrix[i / c][i % c] = nums[i / n][i % n];
        return matrix;
    }
};
