#include <algorithm>
#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid)
    {
        int n = grid.size();
        vector<int> tail_zeros(n);
        for (int i = 0; i < n; ++i) {
            auto it = ranges::find(grid[i].rbegin(), grid[i].rend(), 1);
            tail_zeros[i] = distance(grid[i].rbegin(), it);
        }

        int result = 0;
        for (int i = 0; i < n - 1; ++i) {
            int target = n - 1 - i;
            int j = i;
            while (j < n && tail_zeros[j] < target)
                ++j;
            if (j == n)
                return -1;
            result += (j - i);
            rotate(tail_zeros.begin() + i, tail_zeros.begin() + j, tail_zeros.begin() + j + 1);
        }
        return result;
    }
};
