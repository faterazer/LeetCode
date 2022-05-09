from collections import deque
from typing import List


class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return []
        table = ['', '', 'abc', 'def', 'ghi',
                 'jkl', 'mno', 'pqrs', 'tuv', 'wxyz']
        Q = deque([''])
        for d in digits:
            n = len(Q)
            for _ in range(n):
                s = Q.popleft()
                candidates = table[int(d)]
                Q.extend(deque([s + c for c in candidates]))
        return list(Q)
