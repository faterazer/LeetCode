class Solution:
    def scoreOfParentheses(self, s: str) -> int:
        bal = res = 0
        for i, c in enumerate(s):
            bal += 1 if c == "(" else -1
            if i > 0 and c == ")" and s[i - 1] == "(":
                res += 1 << bal
        return res
