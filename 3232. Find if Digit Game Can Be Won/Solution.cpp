#include <vector>
using namespace std;

class Solution {
public:
    bool canAliceWin(vector<int>& nums)
    {
        int sum1 = 0, sum2 = 0;
        for (const int x : nums) {
            if (x < 10)
                sum1 += x;
            else
                sum2 += x;
        }
        return sum1 != sum2;
    }
};
