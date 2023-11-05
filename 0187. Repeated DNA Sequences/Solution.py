from collections import defaultdict
from typing import List


class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        res, cnt = [], defaultdict(int)
        for i in range(0, len(s) - 9):
            substr = s[i : i + 10]
            cnt[substr] += 1
            if cnt[substr] == 2:
                res.append(substr)
        return res
