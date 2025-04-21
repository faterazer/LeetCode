#include <vector>
using namespace std;

class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper)
    {
        long long mn = 0, mx = 0, x = 0;
        vector<long long> hidden;
        for (int d : differences) {
            x += d;
            mn = min(mn, x);
            mx = max(mx, x);
        }
        return max(upper - mx + mn - lower + 1, 0LL);
    }
};
