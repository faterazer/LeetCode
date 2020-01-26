class Solution:
    def digitSquareSum(self, n: int) -> bool:
        res = 0
        while n:
            res += (n % 10) ** 2
            n //= 10
        return res

    def isHappy(self, n: int) -> bool:
        slow = self.digitSquareSum(n)
        fast = self.digitSquareSum(slow)
        while fast != 1:
            if slow == fast:
                return False 
            slow = self.digitSquareSum(slow)
            fast = self.digitSquareSum(fast)
            fast = self.digitSquareSum(fast)
        return True 
        