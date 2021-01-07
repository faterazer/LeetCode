from typing import List


class Solution:
    def reorderLogFiles(self, logs: List[str]) -> List[str]:
        last = len(logs) - 1
        for i in range(last, -1, -1):
            if logs[i][logs[i].index(' ') + 1].isdigit():
                logs[last], logs[i] = logs[i], logs[last]
                last -= 1
        logs[:last + 1] = sorted(logs[:last + 1], key=lambda x : x[:x.index(' ') + 1])
        logs[:last + 1] = sorted(logs[:last + 1], key=lambda x : x[x.index(' ') + 1:])
        return logs
