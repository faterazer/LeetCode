#include <vector>
using namespace std;

class Solution {
public:
    int sortableIntegers(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> next_dec(n);
        next_dec[n - 1] = n;
        int p = n;
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] > nums[i + 1])
                p = i;
            next_dec[i] = p;
        }

        int result = 0;

        auto solve = [&](int k) -> void {
            int last_max = 0;
            for (int r = k - 1; r < n; r += k) {
                int l = r - k + 1;
                int m = next_dec[l];
                if (m >= r) {
                    if (nums[l] < last_max)
                        return;
                    last_max = nums[r];
                } else {
                    if (next_dec[m + 1] < r || nums[m + 1] < last_max || nums[r] > nums[l])
                        return;
                    last_max = nums[m];
                }
            }
            result += k;
        };

        for (int k = 1; k * k <= n; ++k) {
            if (n % k == 0) {
                solve(k);
                if (k * k < n)
                    solve(n / k);
            }
        }
        return result;
    }
};
