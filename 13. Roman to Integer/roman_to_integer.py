class Solution:
    def __init__(self):
        self.roman_map = {'I': 1, 'V': 5, 'X': 10,
                          'L': 50, 'C': 100, 'D': 500, 'M': 1000}

    def romanToInt(self, s: str) -> int:
        ans = self.roman_map[s[0]]
        for i in range(1, len(s)):
            if self.roman_map[s[i-1]] < self.roman_map[s[i]]:
                ans -= self.roman_map[s[i-1]] * 2
            ans += self.roman_map[s[i]]
        return ans
