#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    long long countBadPairs(vector<int>& nums)
    {
        unordered_map<int, int> cnt;
        long long ans = 0;
        for (size_t j = 0; j < nums.size(); ++j) {
            int d = nums[j] - j;
            ans += j - cnt[d];
            ++cnt[d];
        }
        return ans;
    }
};
