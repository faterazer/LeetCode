class Solution:
    def findKthBit_MK1(self, n: int, k: int) -> str:
        if n == 1:
            return "0"
        mid = 1 << (n - 1)
        if k == mid:
            return "1"
        elif k < mid:
            return self.findKthBit_MK1(n - 1, k)
        else:
            return "0" if self.findKthBit_MK1(n - 1, (1 << n) - k) == "1" else "1"

    def findKthBit_MK2(self, n: int, k: int) -> str:
        if k & 1:
            return str(k // 2 % 2)
        k //= k & -k
        return str(1 - k // 2 % 2)
