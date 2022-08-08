from typing import List


class Solution:
    def exclusiveTime(self, n: int, logs: List[str]) -> List[int]:
        res = [0] * n
        stack = []
        for log in logs:
            fid, ftype, timestamp = log.split(':')
            fid, timestamp = int(fid), int(timestamp)
            if ftype == 'start':
                if stack:
                    res[stack[-1][0]] += timestamp - stack[-1][1]
                stack.append([fid, timestamp])
            else:
                p = stack.pop()
                res[p[0]] += timestamp - p[1] + 1
                if stack:
                    stack[-1][1] = timestamp + 1
        return res
