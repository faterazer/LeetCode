class Solution:
    def isSumEqual(self, firstWord: str, secondWord: str, targetWord: str) -> bool:
        def word2num(word: str) -> int:
            r = 0
            for c in word:
                r = r * 10 + ord(c) - ord('a')
            return r
        
        return word2num(firstWord) + word2num(secondWord) == word2num(targetWord)
