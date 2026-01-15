class Solution:
    def maximizeSquareHoleArea(self, n: int, m: int, hBars: list[int], vBars: list[int]) -> int:
        def longestConsecutive(nums: list[int]) -> int:
            nums.sort()
            mx = cnt = 1
            for i in range(1, len(nums)):
                if nums[i] == nums[i - 1] + 1:
                    cnt += 1
                    mx = max(mx, cnt)
                else:
                    cnt = 1
            return mx

        side = min(longestConsecutive(hBars), longestConsecutive(vBars)) + 1
        return side * side
