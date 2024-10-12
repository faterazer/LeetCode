#include <vector>
using namespace std;

class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums)
    {
        int ans = 0;
        long long st = 0;
        for (int x : nums) {
            if (st & (1LL << x))
                ans ^= x;
            st |= 1LL << x;
        }
        return ans;
    }
};
