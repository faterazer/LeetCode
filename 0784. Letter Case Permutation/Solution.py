from collections import deque
from typing import List


class Solution:
    def letterCasePermutation(self, s: str) -> List[str]:
        queue = deque([[""]])
        for c in s:
            size = len(queue)
            for _ in range(size):
                cur = queue.popleft()
                if c.isalpha():
                    queue.append(cur + [c.lower()])
                    queue.append(cur + [c.upper()])
                else:
                    queue.append(cur + [c])
        return ["".join(v) for v in queue]
