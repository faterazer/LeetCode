#include <queue>
using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid);
};

int Solution::orangesRotting(vector<vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();
    queue<pair<int, int>> Q;
    int fresh_oranges = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == 2)
            {
                Q.push(make_pair(i, j));
            }
            else if (grid[i][j] == 1)
                fresh_oranges++;
        }
    }

    if (fresh_oranges == 0)
        return 0;

    vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int minutes = 0;
    while (!Q.empty())
    {
        size_t len = Q.size();
        for (size_t k = 0; k < len; k++)
        {
            pair<int, int> rotten_orange = Q.front();
            Q.pop();
            for (const auto &dir : dirs)
            {
                int i = rotten_orange.first + dir.first;
                int j = rotten_orange.second + dir.second;
                if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 1)
                    continue;
                grid[i][j] = 2;
                Q.push(make_pair(i, j));
                fresh_oranges--;
            }
        }
        minutes++;
    }
    return fresh_oranges ? -1 : minutes - 1;
}
