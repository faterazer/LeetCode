from typing import List


class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        ret = []
        self.dfs(ret, "", n, n)
        return ret

    def dfs(self, ret: List[str], s: str, lpairs: int, rpairs: int) -> None:
        if rpairs < lpairs:
            return
        if lpairs == 0 and rpairs == 0:
            ret.append(s)
            return
        if lpairs:
            self.dfs(ret, s + "(", lpairs - 1, rpairs)
        if rpairs:
            self.dfs(ret, s + ")", lpairs, rpairs - 1)
