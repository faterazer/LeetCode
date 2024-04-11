class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        if k >= len(num):
            return "0"

        res = []
        for d in num:
            while res and res[-1] > d and k:
                res.pop()
                k -= 1
            if res or d != "0":
                res.append(d)
        if k > 0:
            res = res[:-k]
        return "".join(res) if len(res) > 0 else "0"
