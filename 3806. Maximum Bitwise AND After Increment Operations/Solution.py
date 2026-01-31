class Solution:
    def maximumAND(self, nums: list[int], k: int, m: int) -> int:
        nums.sort()
        if nums[-m] == nums[-1]:
            return nums[-1] + k // m

        n = len(nums)
        ops = [0] * n
        max_width = (nums[-1] + k // m).bit_length()
        result = 0
        for bit in range(max_width - 1, -1, -1):
            target = result | (1 << bit)
            for i, x in enumerate(nums):
                b = (target & ~x).bit_length()
                mask = (1 << b) - 1
                ops[i] = (target & mask) - (x & mask)
            ops.sort()
            if sum(ops[:m]) <= k:
                result = target
        return result
