#include <algorithm>
#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins)
    {
        int mx = ranges::max(costs);
        vector<int> freq(mx + 1);
        for (int cost : costs)
            ++freq[cost];

        int result = 0;
        for (int cost = 1; cost <= mx && cost <= coins; ++cost) {
            int x = min(freq[cost], coins / cost);
            coins -= cost * x;
            result += x;
        }
        return result;
    }
};
