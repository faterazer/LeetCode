class Solution:
    def checkValidString(self, s: str) -> bool:
        min_cnt = max_cnt = 0
        for c in s:
            if c == "(":
                min_cnt += 1
                max_cnt += 1
            elif c == ")":
                min_cnt = max(min_cnt - 1, 0)
                max_cnt -= 1
                if max_cnt < 0:
                    return False
            else:
                min_cnt = max(min_cnt - 1, 0)
                max_cnt += 1
        return min_cnt == 0
