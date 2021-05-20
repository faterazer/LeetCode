class Solution:
    def minOperations(self, s: str) -> int:
        cnt1 = cnt2 = 0
        for i, c in enumerate(s):
            if int(c) != i % 2:
                cnt1 += 1
            else:
                cnt2 += 1
        return min(cnt1, cnt2)
