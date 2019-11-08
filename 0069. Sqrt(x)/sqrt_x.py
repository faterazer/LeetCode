class Solution:
    def mySqrt_MK1(self, x: int) -> int:
        '''
        Binary search. 二分查找
        '''
        if x == 0:
            return x
        
        left, right = 1, x // 2 + 1
        while left <= right:
            mid = (left + right) // 2
            if mid ** 2 < x:
                left = mid + 1
            elif mid ** 2 > x:
                right = mid - 1
            else:
                return mid
        return right

    def mySqrt(self, x: int) -> int:
        '''
        Newton's method. 牛顿法
        '''
        t = x // 2 + 1
        while t * t > x:
            t = (t + x // t) // 2
        return t
