#include <vector>
using namespace std;

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums)
    {
        long long res = 0;
        for (size_t i = 0, j = 0; i < nums.size(); i++) {
            if (nums[i] != 0)
                j = i + 1;
            res += i - j + 1;
        }
        return res;
    }
};
