#include <algorithm>
#include <ranges>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    long long maximumTotalDamage(vector<int>& power)
    {
        unordered_map<int, long long> cnt;
        for (int p : power)
            ++cnt[p];

        vector<pair<int, long long>> f { { 0, 0 } };
        f.insert(f.end(), cnt.begin(), cnt.end());
        ranges::sort(f);

        size_t j = 0;
        for (size_t i = 1; i < f.size(); ++i) {
            while (f[j + 1].first + 2 < f[i].first)
                ++j;
            f[i].second = max(f[i - 1].second, f[j].second + f[i].first * f[i].second);
        }
        return f.back().second;
    }
};
