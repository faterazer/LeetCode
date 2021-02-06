from collections import Counter
from typing import List


class Solution:
    def countCharacters_MK1(self, words: List[str], chars: str) -> int:
        char_table = [0] * 26
        for ch in chars:
            char_table[ord(ch) - ord('a')] += 1

        ret = 0
        for word in words:
            tmp_table = char_table.copy()
            for ch in word:
                tmp_table[ord(ch) - ord('a')] -= 1
                if tmp_table[ord(ch) - ord('a')] < 0:
                    break
            else:
                ret += len(word)
        return ret

    def countCharacters_MK2(self, words: List[str], chars: str) -> int:
        res = 0
        c = Counter(chars)
        for w in words:
            if c == c | Counter(w):
                res += len(w)
        return res
