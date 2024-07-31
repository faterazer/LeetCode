#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w)
    {
        ranges::sort(points, [](const vector<int>& left, const vector<int>& right) { return left[0] < right[0]; });
        int res = 1, beg = points[0][0];
        for (const vector<int>& p : points) {
            if (p[0] - beg > w) {
                res++;
                beg = p[0];
            }
        }
        return res;
    }
};
