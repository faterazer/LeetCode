#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
    int countBeautifulPairs(vector<int>& nums)
    {
        int res = 0, cnt[10] = { 0 };
        for (int x : nums) {
            for (int i = 0; i < 10; i++)
                if (cnt[i] && gcd(x % 10, i) == 1)
                    res += cnt[i];

            while (x > 9)
                x /= 10;
            cnt[x]++;
        }
        return res;
    }
};
