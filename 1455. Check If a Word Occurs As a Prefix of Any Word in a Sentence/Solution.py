class Solution:
    def isPrefixOfWord(self, sentence: str, searchWord: str) -> int:
        for i, w in enumerate(sentence.split(' '), 1):
            if w.startswith(searchWord):
                return i
        return -1
