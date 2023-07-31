from typing import List


class Solution:
    def generatePossibleNextMoves(self, currentState: str) -> List[str]:
        res = []
        for i in range(1, len(currentState)):
            if currentState[i - 1] == currentState[i] == "+":
                res.append(currentState[:i-1] + "--" + currentState[i+1:])
        return res
