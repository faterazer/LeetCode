class Solution:
    def countBalls(self, lowLimit: int, highLimit: int) -> int:
        count = [0] * 46
        for i in range(lowLimit, highLimit + 1):
            count[sum(map(int, str(i)))] += 1
        return max(count)
