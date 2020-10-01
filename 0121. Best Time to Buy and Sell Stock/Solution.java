class Solution {
    /*
        Solution.md
        Approach 2: One pass
        Time complexity: O(n)
        Space complexity: O(1)
     */
    public int maxProfit_MK1(int[] prices) {
        int minPrice = Integer.MAX_VALUE;
        int maxProfit = 0;
        for (int price : prices) {
            minPrice = Math.min(price, minPrice);
            maxProfit = Math.max(maxProfit, price - minPrice);
        }
        return maxProfit;
    }

    /*
        My solution. Time complexity: O(n). Space complexity: O(1).
        Calculate the difference array of prices. Ex: For [7, 1, 5, 3, 6, 4], the difference array
        of prices is [0, -6, 4, -2, 3, -2], and then the problem converts to find the maximum subarray.
        You can read Solution.md of Problem 53. Maximum Subarray to understand details.
     */
    public int maxProfit_MK2(int[] prices) {
        int max = 0, cur = 0;
        for (int i = 1; i < prices.length; i++) {
            int diff = prices[i] - prices[i - 1];
            if (cur < 0)
                cur = diff;
            else
                cur += diff;
            max = Math.max(cur, max);
        }
        return max;
    }
}
