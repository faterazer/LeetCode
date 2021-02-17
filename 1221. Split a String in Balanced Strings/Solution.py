class Solution:
    def balancedStringSplit(self, s: str) -> int:
        cnt = res = 0
        for ch in s:
            cnt += 1 if ch == 'L' else -1
            if not cnt:
                res += 1
        return res
