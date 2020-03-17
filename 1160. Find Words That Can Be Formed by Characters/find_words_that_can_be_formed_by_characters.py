from typing import List


class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
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
