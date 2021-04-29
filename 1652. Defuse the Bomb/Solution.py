from typing import List


class Solution:
    def decrypt(self, code: List[int], k: int) -> List[int]:
        n = len(code)
        res = [0] * n
        if not k:
            return res
        beg, end = 1, k
        if k < 0:
            beg = n + k
            end = n - 1
        range_sum = sum(code[beg:end + 1])
        for i in range(len(res)):
            res[i] = range_sum
            range_sum -= code[beg % n]
            beg += 1
            end += 1
            range_sum += code[end % n]
        return res
