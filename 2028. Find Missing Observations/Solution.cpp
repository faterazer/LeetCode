#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n)
    {
        int missing_sum = mean * (rolls.size() + n) - accumulate(rolls.begin(), rolls.end(), 0);
        if (missing_sum < n || missing_sum > 6 * n)
            return {};
        int div = missing_sum / n, mod = missing_sum % n;
        vector<int> res(n, div);
        for (int i = 0; i < mod; ++i)
            res[i] += 1;
        return res;
    }
};
