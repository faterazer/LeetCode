from typing import List


class Solution:
    def bagOfTokensScore(self, tokens: List[int], power: int) -> int:
        tokens.sort()
        res, score, i, j = 0, 0, 0, len(tokens) - 1
        while i <= j:
            if power >= tokens[i]:
                power -= tokens[i]
                i += 1
                score += 1
                res = max(res, score)
            elif score > 0:
                score -= 1
                power += tokens[j]
                j -= 1
            else:
                break
        return res
