#include <algorithm>
#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
    int largestCombination(vector<int>& candidates)
    {
        int cnt[32] = { 0 };
        for (const int& x : candidates)
            for (int i = 0; i < 32; ++i)
                if (x & (1 << i))
                    ++cnt[i];
        return ranges::max(cnt);
    }
};
