import heapq
from itertools import pairwise


class Solution:
    def minimumPairRemoval(self, nums: list[int]) -> int:
        pq = []
        dec = 0
        for i, (x, y) in enumerate(pairwise(nums)):
            if x > y:
                dec += 1
            pq.append((x + y, i))
        heapq.heapify(pq)

        n = len(nums)
        prev_list = list(range(-1, n - 1))
        next_list = list(range(1, n + 1))

        result = 0
        while dec:
            s, i = heapq.heappop(pq)
            next_i = next_list[i]
            if next_i >= n or nums[i] + nums[next_i] != s:
                continue
            result += 1

            prev_i = prev_list[i]
            if prev_i > -1:
                dec -= nums[prev_i] > nums[i]
                dec += nums[prev_i] > s
                heapq.heappush(pq, (nums[prev_i] + s, prev_i))

            dec -= nums[i] > nums[next_i]

            next_next_i = next_list[next_i]
            if next_next_i < n:
                dec -= nums[next_i] > nums[next_next_i]
                dec += s > nums[next_next_i]
                prev_list[next_next_i] = i
                heapq.heappush(pq, (s + nums[next_next_i], i))

            nums[i] = s
            next_list[i] = next_next_i
            next_list[next_i] = n
        return result
