#include <algorithm>
#include <ranges>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfPairs_MK1(vector<int>& nums1, vector<int>& nums2, int k)
    {
        int ans = 0;
        for (int x : nums1)
            for (int y : nums2)
                if (x % (y * k) == 0)
                    ++ans;
        return ans;
    }

    int numberOfPairs_MK2(vector<int>& nums1, vector<int>& nums2, int k)
    {
        unordered_map<int, int> cnt1, cnt2;
        for (int x : nums1)
            if (x % k == 0)
                ++cnt1[x / k];
        if (cnt1.empty())
            return 0;

        for (int x : nums2)
            ++cnt2[x];

        int ans = 0, mx = ranges::max_element(cnt1)->first;
        for (const auto& [x, c] : cnt2) {
            for (int y = x; y <= mx; y += x)
                if (cnt1.contains(y))
                    ans += cnt1[y] * c;
        }
        return ans;
    }
};
