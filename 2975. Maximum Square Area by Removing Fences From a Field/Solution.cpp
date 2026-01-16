#include <algorithm>
#include <ranges>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences)
    {
        constexpr int MOD = 1'000'000'007;
        if (m == n)
            return 1LL * (m - 1) * (n - 1) % MOD;
        if (hFences.size() > vFences.size())
            return maximizeSquareArea(n, m, vFences, hFences);

        // 计算所有可能的间隔
        auto helper = [](vector<int>& nums) -> unordered_set<int> {
            ranges::sort(nums);
            unordered_set<int> result;
            result.reserve(nums.size() * nums.size() / 2);
            for (size_t j = 1; j < nums.size(); ++j)
                for (size_t i = 0; i < j; ++i)
                    result.insert(nums[j] - nums[i]);
            return result;
        };

        hFences.push_back(1);
        hFences.push_back(m);
        unordered_set<int> hset = helper(hFences);
        vFences.push_back(1);
        vFences.push_back(n);
        unordered_set<int> vset = helper(vFences);
        int side = 0;
        for (int x : hset)
            if (vset.contains(x))
                side = max(side, x);
        return side ? 1LL * side * side % MOD : -1;
    }
};
