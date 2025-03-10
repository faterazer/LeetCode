#include <cmath>
using namespace std;

class Solution {
public:
    int divisorSubstrings(int num, long long k)
    {
        k = pow(10, k);
        int ans = 0;
        for (int x = num; x >= k / 10; x /= 10)
            if (x % k)
                ans += num % (x % k) == 0;
        return ans;
    }
};
