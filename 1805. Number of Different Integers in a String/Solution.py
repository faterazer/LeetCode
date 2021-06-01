import re

class Solution:
    def numDifferentIntegers(self, word: str) -> int:
        return len(set(x.lstrip('0') for x in re.findall('\d+', word)))
