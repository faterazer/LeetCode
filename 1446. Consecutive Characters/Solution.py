class Solution:
    def maxPower(self, s: str) -> int:
        ret = power = 1
        for i in range(1, len(s)):
            if s[i] == s[i - 1]:
                power += 1
            else:
                ret = max(ret, power)
                power = 1
        return max(ret, power)
