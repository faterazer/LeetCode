#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r)
    {
        int n = l.size();
        vector<bool> res(n);
        for (int i = 0; i < n; i++)
            res[i] = check(nums, l[i], r[i]);
        return res;
    }

private:
    bool check(const vector<int>& nums, int left, int right)
    {
        auto [min_val, max_val] = minmax_element(nums.begin() + left, nums.begin() + right + 1);
        int len = right - left + 1;

        if ((*max_val - *min_val) % (len - 1))
            return false;

        int d = (*max_val - *min_val) / (len - 1);
        unordered_set<int> ust(nums.begin() + left, nums.begin() + right + 1);
        for (int i = 1; i < len; i++)
            if (!ust.count(*min_val + (i - 1) * d))
                return false;
        return true;
    }
};
