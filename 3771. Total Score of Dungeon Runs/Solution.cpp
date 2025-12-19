#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    long long totalScore(int hp, vector<int>& damage, vector<int>& requirement)
    {
        int n = damage.size();
        long long result = 0;
        vector<long long> damage_accum(n + 1);
        for (int i = 0; i < n; ++i) {
            damage_accum[i + 1] = damage_accum[i] + damage[i];
            long long need = requirement[i] - hp + damage_accum[i + 1];
            int idx = lower_bound(damage_accum.begin(), damage_accum.begin() + i + 1, need) - damage_accum.begin();
            result += i + 1 - idx;
        }
        return result;
    }
};
