import math
from typing import List


class Solution:
    def distributeCandies_MK1(self, candies: int, num_people: int) -> List[int]:
        '''
        BF.
        '''
        i = 1
        ret = [0] * num_people
        while candies > i:
            ret[(i - 1) % num_people] += i
            candies -= i
            i += 1
        ret[(i - 1) % num_people] += candies
        return ret

    def distributeCandies_MK2(self, candies: int, num_people: int) -> List[int]:
        '''
        Math.
        '''
        n = int(math.sqrt(2 * candies + 0.25) - 0.5)
        rows, cols = divmod(n, num_people)
        ret = [0] * num_people
        for i in range(num_people):
            ret[i] += (i + 1) * rows + rows * (rows - 1) * num_people // 2
            if i < cols:
                ret[i] += 1 + i + rows * num_people
        ret[cols] += candies - n * (n + 1) // 2
        return ret
