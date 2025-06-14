class Solution:
    def minimizeMax(self, nums: list[int], p: int) -> int:
        nums.sort()

        def check(x: int) -> bool:
            cnt = i = 0
            while i < len(nums) - 1:
                if nums[i + 1] - nums[i] <= x:
                    cnt += 1
                    i += 2
                else:
                    i += 1
            return cnt >= p

        lo, hi = 0, nums[-1] - nums[0]
        while lo < hi:
            mid = lo + ((hi - lo) >> 1)
            if check(mid):
                hi = mid
            else:
                lo = mid + 1
        return lo
