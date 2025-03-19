class Solution:
    def minCapability_MK1(self, nums: list[int], k: int) -> int:

        def check(mx: int) -> bool:
            f0 = f1 = 0
            for x in nums:
                if x > mx:
                    f0 = f1
                else:
                    f0, f1 = f1, max(f0 + 1, f1)
            return f1 >= k

        left, right = min(nums), max(nums)
        while left < right:
            mid = left + ((right - left) >> 1)
            if check(mid):
                right = mid
            else:
                left = mid + 1
        return left

    def minCapability_MK2(self, nums: list[int], k: int) -> int:

        def check(mx: int) -> bool:
            cnt = i = 0
            while i < len(nums):
                if nums[i] <= mx:
                    cnt += 1
                    i += 1
                i += 1
            return cnt >= k

        left, right = min(nums), max(nums)
        while left < right:
            mid = left + ((right - left) >> 1)
            if check(mid):
                right = mid
            else:
                left = mid + 1
        return left
