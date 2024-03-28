from typing import List


class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        res, path = [], []
        candidates.sort()

        def dfs(idx: int, t: int) -> None:
            if t == 0:
                res.append(path.copy())
                return

            for i in range(idx, len(candidates)):
                if candidates[i] > t:
                    break
                if i > idx and candidates[i] == candidates[i - 1]:
                    continue
                path.append(candidates[i])
                dfs(i + 1, t - candidates[i])
                path.pop()

        dfs(0, target)
        return res
