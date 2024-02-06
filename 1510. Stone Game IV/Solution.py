class Solution:
    def winnerSquareGame(self, n: int) -> bool:
        f = [False] * (n + 1)
        for i in range(1, n + 1):
            j = 1
            while j * j <= i:
                if not f[i - j * j]:
                    f[i] = True
                    break
                j += 1
        return f[n]
