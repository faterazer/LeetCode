from collections import Counter


class Solution:
    def digitCount(self, num: str) -> bool:
        cnt = Counter(num)
        for i, d in enumerate(num):
            if cnt[str(i)] != int(d):
                return False
        return True
