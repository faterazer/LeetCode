class Solution:
    def numberOfSpecialChars(self, word: str) -> int:
        n = len(word)
        lower_ids = [-1] * 26
        upper_ids = [n] * 26
        for i, c in enumerate(word):
            if "a" <= c <= "z":
                lower_ids[ord(c) - ord("a")] = i
            elif upper_ids[ord(c) - ord("A")] == n:
                upper_ids[ord(c) - ord("A")] = i
        return sum(i != -1 and j != n and i < j for i, j in zip(lower_ids, upper_ids))
