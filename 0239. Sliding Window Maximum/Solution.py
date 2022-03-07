import collections
from typing import List


class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        max_queue = collections.deque()
        for i in range(k):
            while max_queue and max_queue[-1] < nums[i]:
                max_queue.pop()
            max_queue.append(nums[i])
        res = [max_queue[0]]
        for i in range(k, len(nums)):
            if nums[i - k] == max_queue[0]:
                max_queue.popleft()
            while max_queue and max_queue[-1] < nums[i]:
                max_queue.pop()
            max_queue.append(nums[i])
            res.append(max_queue[0])
        return res
