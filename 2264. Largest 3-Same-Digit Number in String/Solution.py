class Solution:
    def largestGoodInteger(self, num: str) -> str:
        return max(("".join(s) for s in zip(num, num[1:], num[2:]) if s[0] == s[1] == s[2]), default="")
