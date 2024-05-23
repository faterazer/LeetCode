#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int longestEqualSubarray_MK1(vector<int>& nums, int k)
    {
        unordered_map<int, vector<int>> num_ids;
        for (size_t i = 0; i < nums.size(); i++)
            num_ids[nums[i]].emplace_back(i);

        int res = 1;
        for (const auto& [_, ids] : num_ids) {
            if (ids.size() <= res)
                continue;

            int length = 1, dels = 0, i = 0;
            for (int j = 1; j < ids.size(); j++) {
                dels += ids[j] - ids[j - 1] - 1;
                length++;
                for (; dels > k && i < j; i++) {
                    dels -= ids[i + 1] - ids[i] - 1;
                    length--;
                }
                res = max(res, length);
            }
        }
        return res;
    }

    int longestEqualSubarray_MK2(vector<int>& nums, int k)
    {
        unordered_map<int, int> cnt;
        int res = 0;
        for (size_t i = 0, j = 0; j < nums.size(); j++) {
            cnt[nums[j]]++;
            while (j - i + 1 - cnt[nums[i]] > k) {
                cnt[nums[i]]--;
                i++;
            }
            res = max(res, cnt[nums[j]]);
        }
        return res;
    }
};
