class Solution:
    def binaryGap(self, n: int) -> int:
        bits = bin(n)[2:]
        last, res = 32, 0
        for i in range(len(bits)):
            if bits[i] == '1':
                res, last = max(res, i - last), i
        return res
