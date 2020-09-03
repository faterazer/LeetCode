#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    /**
     * Hash
     * Time complexity: O(n)
     * Space complexity: O(n)
     */
    int findLHS_MK1(vector<int> &nums)
    {
        int ret = 0;
        unordered_map<int, int> mp;
        for (const int &n : nums)
            mp[n]++;
        for (const auto &it : mp) {
            if (mp.count(it.first + 1))
                ret = max(ret, (it.second + mp[it.first + 1]));
        }
        return ret;
    }

    /**
     * Sort
     * Time complexity: O(nlgn)
     * Space complexity: O(1)
     */
    int findLHS_MK2(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int beg = 0, new_beg = 0, ret = 0, n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[beg] > 1)
                beg = new_beg;
            if (nums[i] != nums[i - 1])
                new_beg = i;
            if (nums[i] - nums[beg] == 1)
                ret = max(ret, i - beg + 1);
        }
        return ret;
    }
};
