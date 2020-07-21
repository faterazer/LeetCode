import numpy as np

class Solution:
    # Binets Method
    def fib_MK1(self, N: int) -> int:
        if N == 0 or N == 1:
            return N
        N -= 1
        A = np.mat([[1, 1], [1, 0]])
        ans = np.mat([[1, 0], [0, 1]])
        while N:
            if N % 2:
                ans *= A
            A *= A
            N //= 2
        return ans[0,0]

    # Fibonacci formula
    def fib_MK2(self, N: int) -> int:
        sqrt5 = 5 ** 0.5
        fibn = ((1 + sqrt5) / 2) ** N - ((1 - sqrt5) / 2) ** N
        return int(fibn / sqrt5)
