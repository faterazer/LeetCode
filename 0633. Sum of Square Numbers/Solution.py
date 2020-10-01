class Solution:
    def judgeSquareSum_MK1(self, c: int) -> bool:
        '''
        Time complexity: O(√clgc).
        Space complexity: O(1).
        '''
        for i in range(int(c ** 0.5) + 1):
            j = int((c - i * i) ** 0.5)
            if i * i + j * j == c:
                return True
        return False

    def judgeSquareSum_MK2(self, c: int) -> bool:
        '''
        Fermat Theorem: Any positive number n is expressible as a sum of two squares if 
        and only if the prime factorization of n, every prime of the form (4k+3) occurs
        even number of times.
        Time complexity: O(√clgc).
        Space complexity: O(1).
        '''
        i = 2
        while i * i <= c:
            if c % i == 0:
                cnt = 0
                while c % i == 0:
                    c //= i
                    cnt += 1
                if i % 4 == 3 and cnt % 2 != 0:
                    return False
            i += 1
        return c % 4 != 3
