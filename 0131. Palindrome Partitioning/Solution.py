class Solution:
    def partition(self, s: str) -> list[list[str]]:
        ans = []
        path = []

        def dfs(i: int) -> None:
            if i == len(s):
                ans.append(path.copy())
                return

            for j in range(i, len(s)):
                if s[i : j + 1] == s[i : j + 1][::-1]:
                    path.append(s[i : j + 1])
                    dfs(j + 1)
                    path.pop()

        dfs(0)
        return ans
