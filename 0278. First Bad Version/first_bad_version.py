# The isBadVersion API is already defined for you.
# @param version, an integer
# @return a bool


def isBadVersion(version):
    pass


class Solution:
    def firstBadVersion(self, n: int) -> int:
        left, right = 0, n
        while left < right:
            mid = left + ((right - left) >> 1)
            if (isBadVersion(mid)):
                right = mid
            else:
                left = mid + 1
        return left
