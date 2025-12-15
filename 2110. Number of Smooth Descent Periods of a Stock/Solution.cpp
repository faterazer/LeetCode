#include <vector>
using namespace std;

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices)
    {
        long long result = 1, dec = 1;
        int n = prices.size();
        for (int i = 1; i < n; ++i) {
            if (prices[i] == prices[i - 1] - 1)
                ++dec;
            else
                dec = 1;
            result += dec;
        }
        return result;
    }
};
