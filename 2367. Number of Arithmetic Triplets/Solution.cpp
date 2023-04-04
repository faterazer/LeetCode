#include <vector>
using namespace std;

class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff)
    {
        int i = 0, j = 0, res = 0;
        for (const int& x : nums) {
            while (nums[i] + diff < x)
                i++;
            if (nums[i] + diff > x)
                continue;
            while (nums[j] + 2 * diff < x)
                j++;
            if (nums[j] + 2 * diff == x)
                res++;
        }
        return res;
    }
};
