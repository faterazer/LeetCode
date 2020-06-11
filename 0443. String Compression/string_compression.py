from typing import List


class Solution:
    def compress(self, chars: List[str]) -> int:
        lasti, i = 0, 0
        while i < len(chars):
            curr_ch, count = chars[i], 0
            while i < len(chars) and chars[i] == curr_ch:
                i += 1
                count += 1
            chars[lasti], lasti = curr_ch, lasti + 1
            if count > 1:
                j = lasti
                while count > 0:
                    chars[lasti], lasti = str(count % 10), lasti + 1
                    count //= 10
                chars[j:lasti] = reversed(chars[j:lasti])
        return lasti
