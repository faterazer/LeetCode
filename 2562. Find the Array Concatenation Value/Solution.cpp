#include <vector>
using namespace std;

class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums)
    {
        long long res = 0;
        int n = nums.size();
        for (int i = 0, j = n - 1; i <= j; i++, j--) {
            if (i == j)
                res += nums[i];
            else {
                for (int x = nums[j]; x; x /= 10)
                    nums[i] *= 10;
                res += nums[i] + nums[j];
            }
        }
        return res;
    }
};
