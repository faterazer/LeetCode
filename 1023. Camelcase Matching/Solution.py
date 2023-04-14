from typing import List


class Solution:
    def camelMatch(self, queries: List[str], pattern: str) -> List[bool]:
        res = []
        for query in queries:
            j = 0
            for i, c in enumerate(query):
                if j < len(pattern) and c == pattern[j]:
                    j += 1
                elif c.isupper():
                    break
            res.append(i + 1 == len(query) and j == len(pattern))
        return res
