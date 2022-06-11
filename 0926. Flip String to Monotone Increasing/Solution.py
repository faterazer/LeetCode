class Solution:
    def minFlipsMonoIncr(self, s: str) -> int:
        cnt_ones = cnt_flips = 0
        for c in s:
            if c == '1':
                cnt_ones += 1
            else:
                cnt_flips = min(cnt_flips + 1, cnt_ones)
        return cnt_flips
