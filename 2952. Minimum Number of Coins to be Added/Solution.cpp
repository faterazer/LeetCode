#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target)
    {
        ranges::sort(coins);
        int res = 0, s = 1, i = 0;
        while (s <= target) {
            if (i < coins.size() && coins[i] <= s)
                s += coins[i++];
            else {
                s *= 2;
                res++;
            }
        }
        return res;
    }
};
