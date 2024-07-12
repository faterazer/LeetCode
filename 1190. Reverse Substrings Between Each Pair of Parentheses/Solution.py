class Solution:
    def reverseParentheses(self, s: str) -> str:
        stack, pair = [], {}
        for i, c in enumerate(s):
            if c == "(":
                stack.append(i)
            elif c == ")":
                j = stack.pop()
                pair[i], pair[j] = j, i

        res = []
        i, d = 0, 1
        while i < len(s):
            if s[i] in "()":
                i, d = pair[i], -d
            else:
                res.append(s[i])
            i += d
        return "".join(res)
