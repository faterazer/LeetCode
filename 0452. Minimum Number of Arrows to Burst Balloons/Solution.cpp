#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points)
    {
        sort(points.begin(), points.end(), [](const vector<int>& left, const vector<int>& right) {
            return left[1] < right[1];
        });

        int pos = points[0][1], res = 1;
        for (const vector<int>& balloon : points) {
            if (balloon[0] > pos) {
                pos = balloon[1];
                ++res;
            }
        }
        return res;
    }
};
