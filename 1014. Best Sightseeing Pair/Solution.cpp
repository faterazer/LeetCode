#include <vector>
using namespace std;

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values)
    {
        int res = -1, max_i = values[0], n = values.size();
        for (int j = 1; j < n; ++j) {
            res = max(res, max_i + values[j] - j);
            max_i = max(max_i, values[j] + j);
        }
        return res;
    }
};
