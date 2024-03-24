from typing import List


class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        res, tmp, n = [], [], len(candidates)
        n = len(candidates)
        candidates.sort()

        def dfs(idx: int, t: int) -> None:
            if t == 0:
                res.append(tmp.copy())
                return

            for i in range(idx, n):
                if candidates[i] > t:
                    break

                tmp.append(candidates[i])
                dfs(i, t - candidates[i])
                tmp.pop()

        dfs(0, target)
        return res
