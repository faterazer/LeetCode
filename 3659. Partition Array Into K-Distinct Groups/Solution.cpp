#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    bool partitionArray(vector<int>& nums, int k)
    {
        if (nums.size() % k != 0)
            return false;
        int groups = nums.size() / k;
        unordered_map<int, int> cnt;
        for (int x : nums)
            if (++cnt[x] > groups)
                return false;
        return true;
    }
};
