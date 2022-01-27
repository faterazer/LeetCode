import re

class Solution:
    def countValidWords(self, sentence: str) -> int:
        pattern = re.compile(r'([a-z]+-[a-z]+|[a-z]*)[!.,]?')
        res = 0
        for word in sentence.split():
            if pattern.fullmatch(word):
                res += 1
        return res
