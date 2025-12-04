#include <algorithm>
#include <functional>
#include <numeric>
#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls)
    {
        int n = robots.size();
        vector<pair<int, int>> sorted_robots;
        sorted_robots.reserve(n + 2);
        sorted_robots.emplace_back(0, 0);
        for (auto [r, d] : views::zip(robots, distance))
            sorted_robots.emplace_back(r, d);
        sorted_robots.emplace_back(numeric_limits<int>::max(), 0);
        ranges::sort(sorted_robots);
        ranges::sort(walls);

        auto count_walls = [&](int start, int end) -> int {
            if (start > end)
                return 0;
            return ranges::upper_bound(walls, end) - ranges::lower_bound(walls, start);
        };

        array<int, 2> dp {};
        for (int i = 1; i <= n; ++i) {
            int prev_pos = sorted_robots[i - 1].first, prev_dist = sorted_robots[i - 1].second;
            int curr_pos = sorted_robots[i].first, curr_dist = sorted_robots[i].second;
            int next_pos = sorted_robots[i + 1].first;

            int left_limit = max(curr_pos - curr_dist, prev_pos + 1);
            int walls_on_left = count_walls(left_limit, curr_pos);
            int candidate_left = dp[0] + walls_on_left;
            int last_right_limit = min(prev_pos + prev_dist, curr_pos - 1);
            int candidate_right = dp[1] + walls_on_left - count_walls(left_limit, last_right_limit);

            int right_limit = min(curr_pos + curr_dist, next_pos - 1);
            int walls_on_right = count_walls(curr_pos, right_limit);
            dp[1] = max(dp[0], dp[1]) + walls_on_right;
            dp[0] = max(candidate_left, candidate_right);
        }
        return max(dp[0], dp[1]);
    }
};
