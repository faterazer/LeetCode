class Solution:
    def queryString(self, s: str, n: int) -> bool:
        if n == 1:
            return "1" in s

        m = len(s)
        k = n.bit_length() - 1
        if m < max(k + n - (1 << k) + 1, (1 << (k - 1)) + k - 1):
            return False

        def check(k: int, lower: int, upper: int) -> bool:
            if lower > upper:
                return True
            seen = set()
            mask = (1 << (k - 1)) - 1
            x = int(s[: k - 1], 2)
            for c in s[k - 1 :]:
                x = ((x & mask) << 1) | int(c)
                if lower <= x <= upper:
                    seen.add(x)
            return len(seen) == upper - lower + 1

        return check(k, n // 2 + 1, (1 << k) - 1) and check(k + 1, 1 << k, n)
