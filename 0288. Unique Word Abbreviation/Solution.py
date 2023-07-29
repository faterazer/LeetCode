from typing import List


class ValidWordAbbr:
    def __init__(self, dictionary: List[str]):
        self.table = {}
        for s in dictionary:
            key = ValidWordAbbr.abbreviate(s)
            if key in self.table and self.table[key] != s:
                self.table[key] = ""
            else:
                self.table[key] = s

    def isUnique(self, word: str) -> bool:
        key = ValidWordAbbr.abbreviate(word)
        if key not in self.table or self.table[key] == word:
            return True
        return False

    @staticmethod
    def abbreviate(s: str):
        if len(s) > 2:
            return s[0] + str(len(s) - 2) + s[-1]
        else:
            return s


# Your ValidWordAbbr object will be instantiated and called as such:
# obj = ValidWordAbbr(dictionary)
# param_1 = obj.isUnique(word)
