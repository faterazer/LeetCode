class Solution:
    def maxRepeating(self, sequence: str, word: str) -> int:
        res = 0
        n, m = len(sequence), len(word)
        nextArr = [0] * len(word) * 2
        j = 0
        for i in range(1, len(nextArr)):
            while j > 0 and word[i % m] != word[j % m]:
                j = nextArr[j - 1]
            if word[i % m] == word[j % m]:
                j += 1
            nextArr[i] = j
        j = 0
        for i in range(n):
            if sequence[i] != word[j % m]:
                if j >= len(nextArr):
                    j = j % m + m
                while j > 0 and sequence[i] != word[j % m]:
                    j = nextArr[j - 1]
            if sequence[i] == word[j % m]:
                j += 1
            res = max(res, j // m)
        return res
