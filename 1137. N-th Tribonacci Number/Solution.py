import numpy


class Solution:
    def tribonacci_MK1(self, n: int) -> int:
        '''
        Time complexity: O(n)
        Space complexity: O(1)
        '''
        if n < 3:
            return 1 if n else 0
        a, b, c = 0, 1, 1
        for i in range(3, n + 1):
            a, b, c = b, c, a + b + c
        return c

    def tribonacci_MK2(self, n: int) -> int:
        '''
        Time complexity: O(lgn)
        Space complexity: O(1)
        '''
        T = numpy.mat([[1, 1, 0]]).transpose()
        if n < 2:
            return int(T[2 - n, 0])
        mtx = numpy.mat([[1, 1, 1], [1, 0, 0], [0, 1, 0]])
        res = mtx ** (n - 2) * T
        return int(res[0, 0])
