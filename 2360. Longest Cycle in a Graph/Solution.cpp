#include <functional>
#include <vector>
using namespace std;

class Solution {
public:
    int longestCycle(vector<int>& edges)
    {
        int n = edges.size(), ans = -1, cur_time = 1;
        vector<int> vis_time(n, 0);
        for (int i = 0; i < n; ++i) {
            int cur = i, start_time = cur_time;
            while (cur != -1 && !vis_time[cur]) {
                vis_time[cur] = cur_time++;
                cur = edges[cur];
            }
            if (cur != -1 && vis_time[cur] >= start_time)
                ans = max(ans, cur_time - vis_time[cur]);
        }
        return ans;
    }
};
