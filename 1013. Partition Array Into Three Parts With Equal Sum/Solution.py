from typing import List


class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        total = sum(A)
        if total % 3:
            return False
        part_sum, target, count = 0, total // 3, 0
        climit = 2 if target else 3
        for num in A:
            part_sum += num
            if part_sum == target:
                part_sum = 0
                count += 1
                if count == climit:
                    return True
        return False
