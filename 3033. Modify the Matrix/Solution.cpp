#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix)
    {
        int n = matrix[0].size();
        for (int j = 0; j < n; j++) {
            int mx = 0;
            for (vector<int>& row : matrix)
                mx = max(mx, row[j]);
            for (vector<int>& row : matrix)
                if (row[j] == -1)
                    row[j] = mx;
        }
        return matrix;
    }
};
