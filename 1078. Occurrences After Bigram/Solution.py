from typing import List


class Solution:
    def findOcurrences(self, text: str, first: str, second: str) -> List[str]:
        res = []
        words = text.split(' ')
        for i in range(2, len(words)):
            if words[i - 2] == first and words[i - 1] == second:
                res.append(words[i])
        return res
