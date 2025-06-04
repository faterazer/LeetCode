class Solution:
    def answerString(self, word: str, numFriends: int) -> str:
        if numFriends == 1:
            return word

        n, i, j = len(word), 0, 1
        while j < n:
            k = 0
            while j + k < n and word[i + k] == word[j + k]:
                k += 1
            if j + k < n and word[i + k] < word[j + k]:
                i, j = j, max(j + 1, i + k + 1)
            else:
                j = j + k + 1
        return word[i : n - max(numFriends - 1 - i, 0)]
