from collections import deque


class Solution:
    def countSubarrays(self, nums: list[int], k: int) -> int:
        result = 0
        max_queue, min_queue = deque([]), deque([])
        left = 0
        for right, x in enumerate(nums):
            while max_queue and max_queue[-1] < x:
                max_queue.pop()
            max_queue.append(x)
            while min_queue and min_queue[-1] > x:
                min_queue.pop()
            min_queue.append(x)

            while (max_queue[0] - min_queue[0]) * (right - left + 1) > k:
                if max_queue[0] == nums[left]:
                    max_queue.popleft()
                if min_queue[0] == nums[left]:
                    min_queue.popleft()
                left += 1

            result += right - left + 1
        return result
