from typing import List


class Solution:
    def numTeams(self, rating: List[int]) -> int:
        n, res = len(rating), 0
        for j in range(n):
            iless = imore = kless = kmore = 0
            for i in range(j):
                if rating[i] < rating[j]:
                    iless += 1
                elif rating[i] > rating[j]:
                    imore += 1
            for k in range(n - 1, j, -1):
                if rating[k] < rating[j]:
                    kless += 1
                elif rating[k] > rating[j]:
                    kmore += 1
            res += iless * kmore + imore * kless
        return res
