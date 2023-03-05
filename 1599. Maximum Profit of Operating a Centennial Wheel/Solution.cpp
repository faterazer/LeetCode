#include <vector>
using namespace std;

class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost)
    {
        if (4 * boardingCost < runningCost)
            return -1;

        int max_profit = 0, cur_profit = 0, res = -1, run = 0, wait = 0, i = 0, n = customers.size();
        while (wait || i < n) {
            if (i < n)
                wait += customers[i++];
            run++;
            cur_profit += min(wait, 4) * boardingCost - runningCost;
            if (cur_profit > max_profit) {
                max_profit = cur_profit;
                res = run;
            }
            wait = max(0, wait - 4);
        }
        return res;
    }
};
