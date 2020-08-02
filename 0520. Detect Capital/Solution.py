import re


class Solution:
    def detectCapitalUse_MK1(self, word: str) -> bool:
        return word.islower() or word.isupper() or word.istitle()

    def detectCapitalUse_MK2(self, word: str) -> bool:
        return re.fullmatch('[A-Z]*|.[a-z]*', word)
