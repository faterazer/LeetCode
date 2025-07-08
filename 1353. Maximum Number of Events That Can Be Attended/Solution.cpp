#include <algorithm>
#include <functional>
#include <numeric>
#include <queue>
#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * 按开始时间分组 + 最小堆。
     * 时间复杂度 O(U + nlog n)，其中 n 为 events 的长度，U = max(endDay_i)。
     */
    int maxEvents_MK1(vector<vector<int>>& events)
    {
        int mx = ranges::max(events, {}, [](const vector<int>& e) { return e[1]; })[1];

        vector<vector<int>> groups(mx + 1);
        for (const vector<int>& e : events)
            groups[e[0]].emplace_back(e[1]);

        int ans = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i <= mx; ++i) {
            while (!pq.empty() && pq.top() < i)
                pq.pop();

            for (int d : groups[i])
                pq.emplace(d);

            if (!pq.empty()) {
                pq.pop();
                ++ans;
            }
        }
        return ans;
    }

    int maxEvents_MK2(vector<vector<int>>& events)
    {
        ranges::sort(events, {}, [](const vector<int>& e) { return e[1]; });
        int mx = events.back()[1];
        vector<int> dsu(mx + 2);
        iota(dsu.begin(), dsu.end(), 0);

        function<int(int)> find = [&](int x) -> int {
            if (dsu[x] != x)
                dsu[x] = find(dsu[x]);
            return dsu[x];
        };

        int ans = 0;
        for (const vector<int> &e : events) {
            int day = find(e[0]);
            if (day <= e[1]) {
                ++ans;
                dsu[day] = day + 1;
            }
        }
        return ans;
    }
};
