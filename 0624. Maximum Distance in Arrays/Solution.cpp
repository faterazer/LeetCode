#include <vector>
using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays)
    {
        int ans = 0, min_val = arrays[0][0], max_val = arrays[0].back();
        for (size_t i = 1; i < arrays.size(); i++) {
            ans = max(ans, max(abs(arrays[i].back() - min_val), abs(max_val - arrays[i][0])));
            min_val = min(min_val, arrays[i][0]);
            max_val = max(max_val, arrays[i].back());
        }
        return ans;
    }
};
