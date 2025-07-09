class Solution:
    def maxFreeTime(self, eventTime: int, k: int, startTime: list[int], endTime: list[int]) -> int:
        n = len(startTime)

        def get(i: int) -> int:
            if i == 0:
                return startTime[0]
            elif i == n:
                return eventTime - endTime[-1]
            else:
                return startTime[i] - endTime[i - 1]

        s = ans = 0
        for i in range(n + 1):
            s += get(i)
            if i < k:
                continue
            ans = max(ans, s)
            s -= get(i - k)
        return ans
