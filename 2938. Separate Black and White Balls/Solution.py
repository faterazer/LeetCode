class Solution:
    def minimumSteps(self, s: str) -> int:
        cnt = res = 0
        for c in s:
            if c == "1":
                cnt += 1
            else:
                res += cnt
        return res
