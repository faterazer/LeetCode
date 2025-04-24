#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums)
    {
        int n = unordered_set<int>(nums.begin(), nums.end()).size();
        unordered_map<int, int> cnt;
        int ans = 0, i = 0;
        for (int x : nums) {
            ++cnt[x];
            while (cnt.size() == n) {
                --cnt[nums[i]];
                if (cnt[nums[i]] == 0)
                    cnt.erase(nums[i]);
                ++i;
            }
            ans += i;
        }
        return ans;
    }
};
