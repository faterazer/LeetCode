import heapq
from itertools import pairwise


class Solution:
    def minimumPairRemoval(self, nums: list[int]) -> int:
        dec = 0
        heap = []
        for i, (x, y) in enumerate(pairwise(nums)):
            if x > y:
                dec += 1
            heap.append((x + y, i))
        heapq.heapify(heap)

        n = len(nums)
        prev_list = list(range(-1, n - 1))
        next_list = list(range(1, n + 1))
        result = 0
        while dec:
            s, i = heapq.heappop(heap)
            if next_list[i] >= n or nums[i] + nums[next_list[i]] != s:
                continue
            result += 1

            prev_i = prev_list[i]
            if prev_i > -1:
                dec -= nums[prev_i] > nums[i]
                dec += nums[prev_i] > s
                heapq.heappush(heap, (nums[prev_i] + s, prev_i))

            next_i = next_list[i]
            dec -= nums[i] > nums[next_i]
            nums[i] = s

            next_next_i = next_list[next_i]
            if next_next_i < n:
                dec -= nums[next_i] > nums[next_next_i]
                dec += s > nums[next_next_i]
                heapq.heappush(heap, (s + nums[next_next_i], i))
                prev_list[next_next_i] = i

            next_list[i] = next_next_i
            next_list[next_i] = n
        return result
