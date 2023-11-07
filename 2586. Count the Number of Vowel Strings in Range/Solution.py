from typing import List


class Solution:
    def vowelStrings(self, words: List[str], left: int, right: int) -> int:
        vowels = "aeiou"
        return sum(s[0] in vowels and s[-1] in vowels for s in words[left : right + 1])
