class Solution:
    def baseNeg2(self, n: int) -> str:
        res = []
        while n:
            res.append(str(n & 1))
            n = -(n >> 1)
        return "0" if not res else "".join(res[::-1])
