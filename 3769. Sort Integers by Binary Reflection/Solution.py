class Solution:
    def sortByReflection(self, nums: list[int]) -> list[int]:
        nums.sort(key=lambda x: (int(bin(x)[2:][::-1]), x))
        return nums
