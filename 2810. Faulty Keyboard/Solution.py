from collections import deque


class Solution:
    def finalString(self, s: str) -> str:
        q, flag = deque([]), True
        for c in s:
            if c == "i":
                flag = not flag
            elif flag:
                q.append(c)
            else:
                q.appendleft(c)
        return "".join(q if flag else reversed(q))
