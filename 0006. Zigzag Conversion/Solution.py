class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1 or len(s) <= numRows:
            return s

        n, res = len(s), []
        a, b = 2 * numRows - 2, 0
        for i in range(numRows):
            j = i
            res.append(s[j])
            while j < n:
                if a > 0 and j + a < n:
                    res.append(s[j + a])
                j += a
                if b > 0 and j + b < n:
                    res.append(s[j + b])
                j += b
            a -= 2
            b += 2
        return "".join(res)
