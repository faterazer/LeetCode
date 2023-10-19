#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int tupleSameProduct(vector<int>& nums)
    {
        unordered_map<int, int> cnt;
        for (size_t i = 0; i < nums.size(); i++)
            for (size_t j = i + 1; j < nums.size(); j++)
                ++cnt[nums[i] * nums[j]];
        int res = 0;
        for (auto& [k, v] : cnt)
            res += v * (v - 1) * 4;
        return res;
    }
};
