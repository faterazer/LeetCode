# The knows API is already defined for you.
# return a bool, whether a knows b
# def knows(a: int, b: int) -> bool:


class Solution:
    def findCelebrity(self, n: int) -> int:
        res = 0
        for i in range(1, n):
            if knows(res, i):
                res = i
        for i in range(n):
            if i == res:
                continue
            if not knows(i, res) or knows(res, i):
                return -1
        return res
