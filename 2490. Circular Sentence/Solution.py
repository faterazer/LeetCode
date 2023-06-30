class Solution:
    def isCircularSentence(self, sentence: str) -> bool:
        return sentence[0] == sentence[-1] and all(
            c != " " or sentence[i - 1] == sentence[i + 1] for i, c in enumerate(sentence)
        )
