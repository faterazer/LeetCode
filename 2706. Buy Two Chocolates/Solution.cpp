#include <vector>
using namespace std;

class Solution {
public:
    int buyChoco(vector<int>& prices, int money)
    {
        int min1 = prices[0], min2 = INT_MAX;
        for (size_t i = 1; i < prices.size(); i++) {
            if (prices[i] <= min1) {
                min2 = min1;
                min1 = prices[i];
            } else if (prices[i] < min2)
                min2 = prices[i];
        }
        int cost = min1 + min2;
        return cost > money ? money : money - cost;
    }
};
