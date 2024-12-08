import bisect
from typing import List


class Solution:
    def maxTwoEvents(self, events: List[List[int]]) -> int:
        events.sort(key=lambda x: x[1])
        pre_max = [0] * len(events)
        pre_max[0] = events[0][2]
        for i in range(1, len(events)):
            pre_max[i] = max(pre_max[i - 1], events[i][2])

        ans = 0
        for i, (start_time, _, value) in enumerate(events):
            j = bisect.bisect_left(events, start_time, key=lambda x: x[1])
            if j == 0:
                ans = max(ans, value)
            else:
                ans = max(ans, pre_max[j - 1] + value)
        return ans
