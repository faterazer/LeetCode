#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int countWays(vector<vector<int>>& ranges)
    {
        sort(ranges.begin(), ranges.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        int res = 1, max_right = -1;
        for (const vector<int>& r : ranges) {
            if (r[0] > max_right)
                res = res * 2 % MOD;
            max_right = max(max_right, r[1]);
        }
        return res;
    }

private:
    const int MOD = 1e9 + 7;
};
