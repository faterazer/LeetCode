#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int longestBalanced(vector<int>& nums)
    {
        int result = 0, n = nums.size();
        unordered_set<int> odd, even;
        for (int i = 0; i < n; ++i) {
            odd.clear();
            even.clear();
            for (int j = i; j < n; ++j) {
                if (nums[j] & 1)
                    odd.insert(nums[j]);
                else
                    even.insert(nums[j]);
                if (odd.size() == even.size())
                    result = max(result, j - i + 1);
            }
        }
        return result;
    }
};
