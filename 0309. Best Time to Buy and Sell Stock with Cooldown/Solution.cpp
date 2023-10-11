#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int pre2_sell = 0, pre1_buy = INT_MIN, pre1_sell = 0;
        for (int price : prices) {
            int cur_buy = max(pre2_sell - price, pre1_buy);
            int cur_sell = max(pre1_sell, cur_buy + price);
            pre2_sell = pre1_sell;
            pre1_buy = cur_buy;
            pre1_sell = cur_sell;
        }
        return pre1_sell;
    }
};
