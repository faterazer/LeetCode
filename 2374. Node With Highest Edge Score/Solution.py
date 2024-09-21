from typing import List


class Solution:
    def edgeScore(self, edges: List[int]) -> int:
        scores = [0] * len(edges)
        for i, dest in enumerate(edges):
            scores[dest] += i
        return scores.index(max(scores))
