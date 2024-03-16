#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums)
    {
        int sum = 0, res = 0, n = nums.size();
        unordered_map<int, int> seen;
        for (int i = 0; i < n; i++) {
            sum += nums[i] ? 1 : -1;
            if (sum == 0)
                res = i + 1;
            else if (seen.count(sum))
                res = max(res, i - seen[sum]);
            else
                seen[sum] = i;
        }
        return res;
    }
};
