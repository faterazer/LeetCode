class Solution:
    def partition(self, s: str) -> list[list[str]]:
        n = len(s)
        is_palindrome = [[True] * n for _ in range(n)]
        for j in range(1, n):
            for i in range(0, j):
                is_palindrome[i][j] = s[i] == s[j] and (j - i < 2 or is_palindrome[i + 1][j - 1])

        ans, path = [], []

        def dfs(i: int) -> None:
            if i == n:
                ans.append(path.copy())
                return

            for j in range(i, n):
                if is_palindrome[i][j]:
                    path.append(s[i : j + 1])
                    dfs(j + 1)
                    path.pop()

        dfs(0)
        return ans
