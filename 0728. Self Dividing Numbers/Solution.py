from typing import List


class Solution:
    def selfDividingNumbers(self, left: int, right: int) -> List[int]:
        return [x for x in range(left, right + 1) if all((i and x % i == 0) for i in map(int, str(x)))]
