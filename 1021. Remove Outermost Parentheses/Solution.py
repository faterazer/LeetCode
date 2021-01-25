class Solution:
    def removeOuterParentheses(self, S: str) -> str:
        res = []
        left = 0
        for ch in S:
            if ch == '(' and left > 0:
                res.append(ch)
            elif ch == ')' and left > 1:
                res.append(ch)
            left += 1 if ch == '(' else -1
        return ''.join(res)
