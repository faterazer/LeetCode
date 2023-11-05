#include <bit>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int findMaximumXOR(vector<int>& nums)
    {
        int res = 0, mask = 0;
        unordered_set<int> seen;
        for (int i = 31; i >= 0; i--) {
            mask |= 1 << i;
            seen.clear();
            int new_res = res | (1 << i);
            for (int x : nums) {
                x &= mask;
                if (seen.contains(new_res ^ x)) {
                    res = new_res;
                    break;
                }
                seen.insert(x);
            }
        }
        return res;
    }
};
