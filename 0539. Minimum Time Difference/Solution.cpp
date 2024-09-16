#include <algorithm>
#include <climits>
#include <ranges>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int findMinDifference(vector<string>& timePoints)
    {
        int n = timePoints.size();
        if (n > 1440)
            return 0;

        ranges::sort(timePoints);
        int res = INT_MAX, pre_minutes = getMinutes(timePoints[0]);
        for (int i = 1; i < n; ++i) {
            int cur_minutes = getMinutes(timePoints[i]);
            res = min(res, cur_minutes - pre_minutes);
            if (res == 0)
                return res;
            pre_minutes = cur_minutes;
        }
        return min(res, getMinutes(timePoints[0]) + 1440 - pre_minutes);
    }

private:
    int getMinutes(const string& s)
    {
        return ((s[0] - '0') * 10 + (s[1] - '0')) * 60 + (s[3] - '0') * 10 + (s[4] - '0');
    }
};
