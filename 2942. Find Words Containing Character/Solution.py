class Solution:
    def findWordsContaining(self, words: list[str], x: str) -> list[int]:
        return [i for i, word in enumerate(words) if x in word]
