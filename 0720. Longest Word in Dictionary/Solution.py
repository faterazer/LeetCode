from typing import List


class Solution:
    def longestWord(self, words: List[str]) -> str:
        words.sort()
        build = set()
        ret = ''
        for word in words:
            if len(word) == 1 or word[:-1] in build:
                build.add(word)
                ret = max(ret, word, key=lambda x: len(x))
        return ret
