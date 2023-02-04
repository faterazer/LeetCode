#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins)
    {
        int max_val = 0;
        sort(coins.begin(), coins.end());
        for (const int& coin : coins)
            if (max_val + 1 >= coin)
                max_val += coin;
            else
                break;
        return max_val + 1;
    }
};
