class Solution:
    def subtractProductAndSum(self, n: int) -> int:
        prod, add = 1, 0
        for x in map(int, str(n)):
            prod *= x
            add += x
        return prod - add
