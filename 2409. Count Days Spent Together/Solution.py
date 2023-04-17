from datetime import datetime


class Solution:
    def countDaysTogether(self, arriveAlice: str, leaveAlice: str, arriveBob: str, leaveBob: str) -> int:
        left = datetime.strptime(max(arriveAlice, arriveBob), r"%m-%d")
        right = datetime.strptime(min(leaveAlice, leaveBob), r"%m-%d")
        return max((right - left).days + 1, 0)
