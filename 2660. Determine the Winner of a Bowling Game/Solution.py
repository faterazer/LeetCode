from typing import List


class Solution:
    def isWinner(self, player1: List[int], player2: List[int]) -> int:
        def cal_score(player: List[int]) -> int:
            res = 0
            pre1 = pre2 = 0
            for hit in player:
                res += 2 * hit if max(pre1, pre2) == 10 else hit
                pre1, pre2 = pre2, hit
            return res

        score1, score2 = cal_score(player1), cal_score(player2)
        if score1 > score2:
            return 1
        elif score1 < score2:
            return 2
        else:
            return 0
