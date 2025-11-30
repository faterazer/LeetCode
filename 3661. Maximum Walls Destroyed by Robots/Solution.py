import bisect
from math import inf


class Solution:
    def maxWalls(self, robots: list[int], distance: list[int], walls: list[int]) -> int:
        sorted_robots = [(0, 0)] + sorted(zip(robots, distance)) + [(inf, 0)]
        walls.sort()

        def count_walls(start: int, end: int) -> int:
            if start > end:
                return 0
            return bisect.bisect_right(walls, end) - bisect.bisect_left(walls, start)

        dp = [0, 0]
        for i in range(1, len(sorted_robots) - 1):
            prev_pos, prev_dist = sorted_robots[i - 1]
            curr_pos, curr_dist = sorted_robots[i]
            next_pos, _ = sorted_robots[i + 1]

            left_limit = max(prev_pos + 1, curr_pos - curr_dist)
            walls_on_left = count_walls(left_limit, curr_pos)
            candidate_from_left = dp[0] + walls_on_left
            prev_right_limit = min(prev_pos + prev_dist, curr_pos - 1)
            candidate_from_right = dp[1] + walls_on_left - count_walls(left_limit, prev_right_limit)

            right_limit = min(curr_pos + curr_dist, next_pos - 1)
            walls_on_right = count_walls(curr_pos, right_limit)
            dp = [max(candidate_from_left, candidate_from_right), max(dp) + walls_on_right]
        return max(dp)
