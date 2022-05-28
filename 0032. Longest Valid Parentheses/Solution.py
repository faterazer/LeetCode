class Solution:
    def longestValidParentheses(self, s: str) -> int:
        l_cnt = r_cnt = res = 0
        for c in s:
            if c == '(':
                l_cnt += 1
            else:
                r_cnt += 1
            if l_cnt < r_cnt:
                l_cnt = r_cnt = 0
            elif l_cnt == r_cnt:
                res = max(res, 2 * l_cnt)
        l_cnt = r_cnt = 0
        for c in s[::-1]:
            if c == '(':
                l_cnt += 1
            else:
                r_cnt += 1
            if l_cnt > r_cnt:
                l_cnt = r_cnt = 0
            elif l_cnt == r_cnt:
                res = max(res, 2 * l_cnt)
        return res
