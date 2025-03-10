class Solution:
    def divisorSubstrings(self, num: int, k: int) -> int:
        k = 10**k
        ans = 0
        x = num
        while x >= k // 10:
            y, d = divmod(x, k)
            if d and num % d == 0:
                ans += 1
            x //= 10
        return ans
