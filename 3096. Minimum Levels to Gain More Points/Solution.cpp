#include <vector>
using namespace std;

class Solution {
public:
    int minimumLevels(vector<int>& possible)
    {
        int n = possible.size();
        int s = reduce(possible.begin(), possible.end(), 0) * 2 - n;
        int pre_sum = 0;
        for (int i = 0; i < n - 1; i++) {
            pre_sum += possible[i] * 2 - 1;
            if (pre_sum > s - pre_sum)
                return i + 1;
        }
        return -1;
    }
};
