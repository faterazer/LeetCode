#include <math.h>

int minOperationsMaxProfit(int* customers, int customersSize, int boardingCost, int runningCost)
{
    if (4 * boardingCost < runningCost)
        return -1;

    int max_profit = 0, cur_profit = 0, res = -1, run = 0, wait = 0, i = 0;
    while (wait || i < customersSize) {
        if (i < customersSize)
            wait += customers[i++];
        run++;
        cur_profit += fmin(wait, 4) * boardingCost - runningCost;
        if (cur_profit > max_profit) {
            max_profit = cur_profit;
            res = run;
        }
        wait = fmax(0, wait - 4);
    }
    return res;
}
