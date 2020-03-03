from collections import Counter


class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        s, g = Counter(secret), Counter(guess)
        A = sum(i == j for i, j in zip(secret, guess))
        B = sum((s & g).values()) - A
        return '{}A{}B'.format(A, B)
