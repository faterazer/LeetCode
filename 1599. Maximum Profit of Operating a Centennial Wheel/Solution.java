class Solution {
    public int minOperationsMaxProfit(int[] customers, int boardingCost, int runningCost) {
        if (4 * boardingCost < runningCost) {
            return -1;
        }

        int maxProfit = 0, curProfit = 0, res = -1, run = 0, wait = 0, i = 0;
        while (wait != 0 || i < customers.length) {
            if (i < customers.length) {
                wait += customers[i++];
            }
            run++;
            curProfit += Math.min(wait, 4) * boardingCost - runningCost;
            if (curProfit > maxProfit) {
                maxProfit = curProfit;
                res = run;
            }
            wait = Math.max(0, wait - 4);
        }
        return res;
    }
}
