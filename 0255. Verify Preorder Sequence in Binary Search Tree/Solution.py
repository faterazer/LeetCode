from typing import List


class Solution:
    def verifyPreorder(self, preorder: List[int]) -> bool:
        lower_bound, tp = float("-inf"), 0
        for p in preorder:
            if p < lower_bound:
                return False
            while tp > 0 and p > preorder[tp - 1]:
                tp -= 1
                lower_bound = preorder[tp]
            preorder[tp] = p
            tp += 1
        return True
