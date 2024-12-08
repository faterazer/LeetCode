#include <algorithm>
#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events)
    {
        ranges::sort(events, [](const vector<int>& left, const vector<int>& right) { return left[1] < right[1]; });
        vector<int> pre_max(events.size(), 0);
        pre_max[0] = events[0][2];
        for (size_t i = 1; i < events.size(); ++i)
            pre_max[i] = max(events[i][2], pre_max[i - 1]);

        int ans = 0;
        for (const vector<int>& e : events) {
            int k = lower_bound(events.begin(), events.end(), e[0], [](vector<int>& event, int value) { return event[1] < value; }) - events.begin();
            if (k == 0)
                ans = max(ans, e[2]);
            else
                ans = max(ans, pre_max[k - 1] + e[2]);
        }
        return ans;
    }
};
