#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs)
    {
        sort(pairs.begin(), pairs.end(), [](const vector<int>& left, const vector<int>& right) {
            return left[1] < right[1];
        });
        int last = pairs[0][1], res = 1;
        for (size_t i = 1; i < pairs.size(); ++i) {
            if (pairs[i][0] > last) {
                last = pairs[i][1];
                ++res;
            }
        }
        return res;
    }
};
