#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int centeredSubarrays(vector<int>& nums)
    {
        unordered_set<int> seen;
        int n = nums.size(), result = 0;
        for (int i = 0; i < n; ++i) {
            seen.clear();
            int s = 0;
            for (int j = i; j < n; ++j) {
                s += nums[j];
                seen.insert(nums[j]);
                result += seen.contains(s);
            }
        }
        return result;
    }
};
