class Solution:
    def maxDiff(self, num: int) -> int:
        s = str(num)
        mx = num
        for c in s:
            if c != "9":
                mx = int(s.replace(c, "9"))
                break

        mn = num
        if s[0] != "1":
            mn = int(s.replace(s[0], "1"))
        else:
            for c in s[1:]:
                if c > "1":
                    mn = int(s.replace(c, "0"))
                    break
        return mx - mn
