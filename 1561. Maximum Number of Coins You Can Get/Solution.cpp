#include <algorithm>
#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& piles)
    {
        ranges::sort(piles, greater<int>());
        int ans = 0;
        for (int i = 0; i < piles.size() / 3; ++i)
            ans += piles[2 * i + 1];
        return ans;
    }
};
