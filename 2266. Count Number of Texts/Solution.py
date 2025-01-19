class Solution:
    def countTexts(self, pressedKeys: str) -> int:
        MOD, n = 10**9 + 7, len(pressedKeys) + 1
        f = [0] * n
        f[0] = 1
        for i in range(1, n):
            m = 4 if pressedKeys[i - 1] in "79" else 3
            j = i - 1
            while j > 0 and i - j < m and pressedKeys[i - 1] == pressedKeys[j - 1]:
                f[i] += f[j - 1]
                j -= 1
            f[i] += f[i - 1]
        return f[-1] % MOD
