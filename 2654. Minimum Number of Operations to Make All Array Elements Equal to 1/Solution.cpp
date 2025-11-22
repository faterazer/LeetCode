#include <algorithm>
#include <numeric>
#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
    int minOperations_MK1(vector<int>& nums)
    {
        auto n = ssize(nums);
        int gcd_all = 0, cnt1 = 0;
        for (int x : nums) {
            gcd_all = gcd(gcd_all, x);
            cnt1 += x == 1;
        }
        if (gcd_all > 1)
            return -1;
        if (cnt1)
            return n - cnt1;

        ptrdiff_t min_size = n;
        for (ptrdiff_t i = 0; i < n; ++i) {
            int g = 0;
            for (ptrdiff_t j = i; j < n; ++j) {
                g = gcd(g, nums[j]);
                if (g == 1) {
                    min_size = min(min_size, j - i);
                    break;
                }
            }
        }
        return min_size - 1 + n;
    }

    // logtrick
    int minOperations_MK2(vector<int>& nums)
    {
        auto n = ssize(nums);
        int gcd_all = 0, cnt1 = 0;
        for (int x : nums) {
            gcd_all = gcd(gcd_all, x);
            cnt1 += x == 1;
        }
        if (gcd_all > 1)
            return -1;
        if (cnt1)
            return n - cnt1;

        ptrdiff_t min_size = n;
        vector<pair<int, int>> g;
        for (ptrdiff_t i = 0; i < n; ++i) {
            g.emplace_back(nums[i], i);

            int j = 0;
            for (auto& p : g) {
                p.first = gcd(p.first, nums[i]);
                if (g[j].first == p.first)
                    g[j].second = p.second;
                else
                    g[++j] = move(p);
            }
            g.resize(j + 1);
            if (g[0].first == 1)
                min_size = min(min_size, i - g[0].second);
        }
        return min_size + n - 1;
    }
};
