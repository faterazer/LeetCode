#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points)
    {
        constexpr int MOD = 1e9 + 7;
        unordered_map<int, int> y_count;
        for (const vector<int>& p : points)
            ++y_count[p[1]];

        int result = 0, comb_accum = 0;
        for (const auto& [_, count] : y_count) {
            if (count < 2)
                continue;
            int comb = 1LL * count * (count - 1) / 2 % MOD;
            result = (result + 1LL * comb_accum * comb) % MOD;
            comb_accum = (comb_accum + comb) % MOD;
        }
        return result;
    }
};
