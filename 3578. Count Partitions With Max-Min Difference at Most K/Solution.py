from collections import deque


class Solution:
    def countPartitions(self, nums: list[int], k: int) -> int:
        MOD = 10**9 + 7
        dp = [1] + [0] * len(nums)
        window_sum = 0
        min_queue, max_queue = deque([]), deque([])
        i = 0
        for j, x in enumerate(nums):
            window_sum += dp[j]
            while min_queue and min_queue[-1][0] >= x:
                min_queue.pop()
            min_queue.append((x, j))
            while max_queue and max_queue[-1][0] <= x:
                max_queue.pop()
            max_queue.append((x, j))

            while max_queue[0][0] - min_queue[0][0] > k:
                window_sum -= dp[i]
                i += 1
                if i > min_queue[0][1]:
                    min_queue.popleft()
                if i > max_queue[0][1]:
                    max_queue.popleft()
            dp[j + 1] = window_sum % MOD
        return dp[-1]
