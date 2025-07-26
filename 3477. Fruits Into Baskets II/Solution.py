class Solution:
    def numOfUnplacedFruits(self, fruits: list[int], baskets: list[int]) -> int:
        ans = 0
        for fruit in fruits:
            for j, basket in enumerate(baskets):
                if fruit <= basket:
                    baskets[j] = 0
                    break
            else:
                ans += 1
        return ans
