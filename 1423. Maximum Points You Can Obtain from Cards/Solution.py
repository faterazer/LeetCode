from typing import List


class Solution:
    def maxScore(self, cardPoints: List[int], k: int) -> int:
        window_size = len(cardPoints) - k
        window_sum= sum(cardPoints[:window_size])
        min_sum = window_sum
        for i in range(window_size, len(cardPoints)):
            window_sum += cardPoints[i] - cardPoints[i - window_size]
            min_sum = min(min_sum, window_sum)
        return sum(cardPoints) - min_sum
