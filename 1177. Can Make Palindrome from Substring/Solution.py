from typing import List


class Solution:
    def canMakePaliQueries(self, s: str, queries: List[List[int]]) -> List[bool]:
        pre_sum = [0] * (len(s) + 1)
        for i, c in enumerate(s):
            bit = 1 << (ord(c) - ord("a"))
            pre_sum[i + 1] = pre_sum[i] ^ bit

        res = []
        for left, right, k in queries:
            cnt = (pre_sum[right + 1] ^ pre_sum[left]).bit_count()
            res.append(cnt // 2 <= k)
        return res
