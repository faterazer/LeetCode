#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee)
    {
        int f0 = INT_MIN, f1 = 0;
        for (int price : prices) {
            f0 = max(f1 - price, f0);
            f1 = max(f1, f0 + price - fee);
        }
        return f1;
    }
};
