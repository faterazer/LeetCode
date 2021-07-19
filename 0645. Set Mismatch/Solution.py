from typing import List

class Solution:
    def findErrorNums_MK1(self, nums: List[int]) -> List[int]:
        '''
        Time complexity: O(n).
        Space complexity: O(1).
        '''
        dup, total, n = 0, 0, len(nums)
        for num in nums:
            if nums[abs(num) - 1] < 0:
                dup = abs(num)
            else:
                nums[abs(num) - 1] *= -1
            total += abs(num)
        return [dup, (1 + n) * n // 2 - total + dup]

    def findErrorNums_MK2(self, nums: List[int]) -> List[int]:
        '''
        Time complexity: O(n)
        Space complexity: O(1)
        '''
        sum1 = sum(nums)
        sum2 = sum(e * e for e in nums)
        n = len(nums)
        x = n * (n + 1) // 2 - sum1
        y = (n * (n + 1) * (2 * n + 1) // 6 - sum2) // x
        return [(y - x) // 2, (x + y) // 2]

    def findErrorNums_MK3(self, nums: List[int]) -> List[int]:
        '''
        Time complexity: O(n)
        Space complexity: O(1)
        '''
        xor = 0
        for num in nums:
            xor ^= num
        for i in range(1, len(nums) + 1):
            xor ^= i
        lowbit = xor & (-xor)
        x1 = x2 = 0
        for num in nums:
            if num & lowbit:
                x1 ^= num
            else:
                x2 ^= num
        for i in range(1, len(nums) + 1):
            if i & lowbit:
                x1 ^= i
            else:
                x2 ^= i
        for num in nums:
            if x1 == num:
                return [x1, x2]
            elif x2 == num:
                return [x2, x1]
