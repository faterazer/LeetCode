#include <vector>
using namespace std;

class Solution {
public:
    long long minArraySum(vector<int>& nums, int k)
    {
        vector<long long> min_f(k, -1);
        min_f[0] = 0;
        int sum = 0;
        long long f = 0;
        for (int x : nums) {
            sum = (sum + x) % k;
            f += x;
            if (min_f[sum] != -1)
                f = min(f, min_f[sum]);
            min_f[sum] = f;
        }
        return f;
    }
};
