class Solution:
    def triangleType(self, nums: list[int]) -> str:
        nums.sort()
        a, b, c = nums
        if a + b <= c:
            return "none"
        elif a == b == c:
            return "equilateral"
        elif a == b or b == c:
            return "isosceles"
        else:
            return "scalene"
