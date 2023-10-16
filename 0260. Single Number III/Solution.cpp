#include <vector>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums)
    {
        int xor_sum = 0;
        for (int x : nums)
            xor_sum ^= x;

        int lowbit = xor_sum == INT_MIN ? xor_sum : xor_sum & -xor_sum;
        vector<int> res(2, 0);
        for (int x : nums) {
            if (x & lowbit)
                res[0] ^= x;
            else
                res[1] ^= x;
        }
        return res;
    }
};
