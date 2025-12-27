#include <algorithm>
#include <queue>
#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings)
    {
        ranges::sort(meetings, {}, [](const vector<int>& meeting) { return meeting[0]; });
        priority_queue<int, vector<int>, greater<>> available;
        for (int i = 0; i < n; ++i)
            available.emplace(i);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> occupied;
        vector<int> cnt(n);
        for (const vector<int>& meeting : meetings) {
            int start = meeting[0], end = meeting[1];
            while (!occupied.empty() && occupied.top().first <= start) {
                available.emplace(occupied.top().second);
                occupied.pop();
            }
            if (available.empty()) {
                auto [t, room] = occupied.top();
                occupied.pop();
                ++cnt[room];
                occupied.emplace(t + end - start, room);
            } else {
                int room = available.top();
                available.pop();
                ++cnt[room];
                occupied.emplace(end, room);
            }
        }
        return ranges::max_element(cnt) - cnt.begin();
    }
};
