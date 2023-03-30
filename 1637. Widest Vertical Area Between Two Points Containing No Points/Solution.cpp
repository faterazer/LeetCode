#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points)
    {
        sort(points.begin(), points.end());
        int res = 0;
        for (size_t i = 1; i < points.size(); i++)
            res = max(res, points[i][0] - points[i - 1][0]);
        return res;
    }
};
