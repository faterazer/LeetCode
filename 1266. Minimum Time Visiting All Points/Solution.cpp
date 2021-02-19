#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    int minTimeToVisitAllPoints(vector<vector<int>> &points)
    {
        int cost = 0;
        for (size_t i = 1; i < points.size(); i++)
            cost += max(abs(points[i - 1][0] - points[i][0]), abs(points[i - 1][1] - points[i][1]));
        return cost;
    }
};
