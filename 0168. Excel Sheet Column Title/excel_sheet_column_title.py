class Solution:
    def convertToTitle_MK1(self, n: int) -> str:
        s = ''
        while n:
            n -= 1
            n, t = divmod(n, 26)
            s += chr(t + ord('A'))
        return s[::-1]

    def convertToTitle_MK2(self, n: int) -> str:
        return self.convertToTitle((n - 1) // 26) + chr((n - 1) % 26 + ord('A')) if n else ''
