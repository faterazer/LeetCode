from typing import List


class Solution:
    def maxProfit_MK1(self, prices: List[int]) -> int:
        '''
        Solution.md
        Approach 2: One pass
        Time complexity: O(n)
        Space complexity: O(1)
        '''
        if not prices:
            return 0
        max_profit, min_price = 0, prices[0]
        for i in range(1, len(prices)):
            if prices[i] < min_price:
                min_price = prices[i]
            else:
                max_profit = max(max_profit, prices[i] - min_price)
        return max_profit

    def maxProfit_MK2(self, prices: List[int]) -> int:
        '''
        My solution. Time complexity: O(n). Space complexity: O(1).
        Calculate the difference array of prices. Ex: For [7, 1, 5, 3, 6, 4], the difference array
        of prices is [0, -6, 4, -2, 3, -2], and then the problem converts to find the maximum subarray.
        You can read Solution.md of Problem 53. Maximum Subarray to understand details.
        '''
        max_profit, max_curr = 0, 0
        for i in range(1, len(prices)):
            diff = prices[i] - prices[i-1]
            if max_curr < 0:
                max_curr = diff
            else:
                max_curr += diff
            max_profit = max(max_profit, max_curr)
        return max_profit
