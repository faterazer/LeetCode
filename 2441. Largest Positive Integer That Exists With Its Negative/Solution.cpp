#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int findMaxK(vector<int>& nums)
    {
        unordered_set<int> seen;
        int res = -1;
        for (const int& x : nums) {
            if (seen.count(-x))
                res = max(res, abs(x));
            seen.emplace(x);
        }
        return res;
    }
};
