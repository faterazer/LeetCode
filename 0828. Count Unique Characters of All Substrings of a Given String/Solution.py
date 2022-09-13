class Solution:
    def uniqueLetterString(self, s: str) -> int:
        indices = [[-1, -1] for _ in range(26)]
        n, res = len(s), 0
        for i, c in enumerate(s):
            idx = ord(c) - ord('A')
            res += (indices[idx][1] - indices[idx][0]) * (i - indices[idx][1])
            indices[idx][0], indices[idx][1] = indices[idx][1], i
        for i in range(26):
            res += (indices[i][1] - indices[i][0]) * (n - indices[i][1])
        return res
