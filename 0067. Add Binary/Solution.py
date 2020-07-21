class Solution:
    def addBinary_MK1(self, a: str, b: str) -> str:
        apos, bpos = len(a) - 1, len(b) - 1
        carry = 0
        ans = ""
        while apos >= 0 or bpos >= 0 or carry:
            adigit, bdigit = 0, 0
            if apos >= 0:
                adigit = int(a[apos])
                apos -= 1
            if bpos >= 0:
                bdigit = int(b[bpos])
                bpos -= 1
            t = adigit + bdigit + carry
            carry = t >> 1
            ans = str(t & 1) + ans
        return ans

    def addBinary_MK2(self, a: str, b: str) -> str:
        if len(a) == 0:
            return b
        elif len(b) == 0:
            return a
        elif a[-1] == '1' and b[-1] == '1':
            return self.addBinary_MK2(self.addBinary_MK2(a[:-1], b[:-1]), '1') + '0'
        else:
            return self.addBinary_MK2(a[:-1], b[:-1]) + str(int(a[-1]) + int(b[-1]))

    def addBinary_MK3(self, a: str, b: str) -> str:
        return bin(eval('0b' + a) + eval('0b' + b))[2:]
