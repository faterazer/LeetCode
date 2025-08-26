#include <cmath>
#include <vector>
using namespace std;

class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions)
    {
        int max_area = 0, max_diagonal_squared = 0;
        for (const vector<int>& d : dimensions) {
            int current_diagonal_squared = d[0] * d[0] + d[1] * d[1];
            if (current_diagonal_squared > max_diagonal_squared) {
                max_diagonal_squared = current_diagonal_squared;
                max_area = d[0] * d[1];
            } else if (current_diagonal_squared == max_diagonal_squared)
                max_area = max(max_area, d[0] * d[1]);
        }
        return max_area;
    }
};
