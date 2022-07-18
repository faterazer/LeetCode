from typing import List


class Solution:
    def makesquare(self, matchsticks: List[int]) -> bool:
        all_len = sum(matchsticks)
        side_len, remain = divmod(all_len, 4)
        if remain != 0:
            return False
        if any(stick > side_len for stick in matchsticks):
            return False
        matchsticks.sort(reverse=True)

        def dfs(idx: int, cur: int, remain: int, state: int) -> bool:
            if remain == 0:
                return True
            if cur == side_len:
                return dfs(0, 0, remain - 1, state)
            i = idx
            while i < len(matchsticks):
                if state & (1 << i):
                    i += 1
                    continue
                if cur + matchsticks[i] > side_len:
                    i += 1
                    continue
                if dfs(i + 1, cur + matchsticks[i], remain, state | (1 << i)):
                    return True
                while i < len(matchsticks) - 1 and matchsticks[i] == matchsticks[i + 1]:
                    i += 1
                i += 1
            return False

        return dfs(0, 0, 4, 0)
