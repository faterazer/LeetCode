import re


class Solution:
    def freqAlphabets(self, s: str) -> str:
        base = ord('a') - 1
        return ''.join(chr(int(x[:2]) + base) for x in re.findall(r'\d{2}#|\d', s))
