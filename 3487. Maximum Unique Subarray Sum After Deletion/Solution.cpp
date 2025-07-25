#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSum(vector<int>& nums)
    {
        unordered_set<int> seen;
        int pos_sum = 0, max_neg = INT_MIN;
        for (int x : nums) {
            if (x < 0)
                max_neg = max(x, max_neg);
            else if (!seen.contains(x)) {
                pos_sum += x;
                seen.emplace(x);
            }
        }
        return seen.empty() ? max_neg : pos_sum;
    }
};
