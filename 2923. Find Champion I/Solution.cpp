#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
    int findChampion(vector<vector<int>>& grid)
    {
        int n = grid.size(), res = 0;
        for (int i = 1; i < n; i++)
            if (grid[i][res])
                res = i;
        return res;
    }
};
