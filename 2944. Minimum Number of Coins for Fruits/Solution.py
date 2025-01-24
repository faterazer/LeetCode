from collections import deque
from typing import List


class Solution:
    def minimumCoins(self, prices: List[int]) -> int:
        f = [0] * (len(prices) + 1)
        mono_queue = deque([])
        for i in range(1, len(prices) + 1):
            while mono_queue and mono_queue[0] < (i + 1) // 2:
                mono_queue.popleft()
            while mono_queue and f[mono_queue[-1] - 1] + prices[mono_queue[-1] - 1] >= f[i - 1] + prices[i - 1]:
                mono_queue.pop()
            mono_queue.append(i)
            f[i] = f[mono_queue[0] - 1] + prices[mono_queue[0] - 1]
        return f[-1]
