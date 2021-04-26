from typing import List


class Solution:
    def slowestKey(self, releaseTimes: List[int], keysPressed: str) -> str:
        n = len(releaseTimes)
        res = keysPressed[0]
        max_dur = releaseTimes[0]
        for i in range(1, n):
            dur = releaseTimes[i] - releaseTimes[i - 1]
            if dur > max_dur:
                max_dur = dur
                res = keysPressed[i]
            elif dur == max_dur:
                res = max(res, keysPressed[i])
        return res
