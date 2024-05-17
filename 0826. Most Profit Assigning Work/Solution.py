from typing import List


class Solution:
    def maxProfitAssignment(self, difficulty: List[int], profit: List[int], worker: List[int]) -> int:
        jobs = sorted(zip(difficulty, profit))
        worker.sort()
        res = i = max_profit = 0
        for w in worker:
            while i < len(jobs) and jobs[i][0] <= w:
                max_profit = max(max_profit, jobs[i][1])
                i += 1
            res += max_profit
        return res
