class Solution:
    def secondHighest(self, s: str) -> int:
        digits = set(d for d in s if d.isdigit())
        return int(sorted(digits, reverse=True)[1]) if len(digits) > 1 else -1
