class Solution:
    def modifyString(self, s: str) -> str:
        res = []
        sentinel = '#'
        for i, c in enumerate(s):
            if c != '?':
                res.append(c)
            else:
                lc = sentinel if i == 0 else res[-1]
                rc = sentinel if i == len(s) - 1 or s[i + 1] == '?' else s[i + 1]
                res.append({'a', 'b', 'c'}.difference({lc, rc}).pop())
        return ''.join(res)
