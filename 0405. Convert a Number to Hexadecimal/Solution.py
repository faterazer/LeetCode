class Solution:
    def __init__(self):
        self.dec2hex = "0123456789abcdef"

    def toHex(self, num: int) -> str:
        if num == 0:
            return '0'

        ret = ''
        for _ in range(8):
            ret = self.dec2hex[num & 15] + ret
            num >>= 4
            if not num:
                break
        return ret
