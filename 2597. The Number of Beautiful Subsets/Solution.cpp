#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k)
    {
        unordered_map<int, int> cnt;
        for (int x : nums)
            ++cnt[x];

        int ans = 1;
        for (auto& [x, c] : cnt) {
            if (cnt.contains(x - k))
                continue;

            int f0 = 1, f1 = 1 << c;
            for (int y = x + k; cnt.contains(y); y += k) {
                int f2 = f1 + f0 * ((1 << cnt[y]) - 1);
                f0 = f1;
                f1 = f2;
            }
            ans *= f1;
        }
        return ans - 1;
    }
};
