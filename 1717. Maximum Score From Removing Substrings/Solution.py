class Solution:
    def maximumGain(self, s: str, x: int, y: int) -> int:
        if x < y:
            x, y = y, x
            s = s[::-1]

        ans = a_cnt = b_cnt = 0
        for c in s:
            if c == "a":
                a_cnt += 1
            elif c == "b":
                if a_cnt > 0:
                    a_cnt -= 1
                    ans += x
                else:
                    b_cnt += 1
            else:
                ans += min(a_cnt, b_cnt) * y
                a_cnt = b_cnt = 0
        return ans + min(a_cnt, b_cnt) * y
