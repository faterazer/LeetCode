from typing import List


class Solution:
    def findWinningPlayer(self, skills: List[int], k: int) -> int:
        max_i = cnt = 0
        for i in range(1, len(skills)):
            if skills[i] > skills[max_i]:
                max_i = i
                cnt = 0
            cnt += 1
            if cnt == k:
                break
        return max_i
