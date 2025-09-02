#include <algorithm>
#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points)
    {
        ranges::sort(points, [](const vector<int>& left, const vector<int>& right) {
            if (left[0] != right[0])
                return left[0] < right[0];
            else
                return left[1] > right[1];
        });

        int ans = 0;
        for (size_t i = 1; i < points.size(); ++i) {
            int c = INT_MAX;
            for (int j = i - 1; j >= 0; --j) {
                if (points[j][1] < c && points[j][1] >= points[i][1]) {
                    ++ans;
                    c = points[j][1];
                }
            }
        }
        return ans;
    }
};
