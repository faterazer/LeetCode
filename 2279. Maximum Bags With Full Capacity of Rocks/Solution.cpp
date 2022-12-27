#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks)
    {
        vector<int> diff(capacity.size());
        for (size_t i = 0; i < diff.size(); i++)
            diff[i] = capacity[i] - rocks[i];
        sort(diff.begin(), diff.end());

        int res = 0;
        for (const int& d : diff) {
            if (additionalRocks < d)
                break;
            additionalRocks -= d;
            res += 1;
        }
        return res;
    }
};
