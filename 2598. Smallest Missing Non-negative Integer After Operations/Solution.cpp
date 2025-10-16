#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value)
    {
        unordered_map<int, int> cnt;
        for (int x : nums)
            ++cnt[(x % value + value) % value];
        int ans = 0;
        while (cnt[ans % value]-- > 0)
            ++ans;
        return ans;
    }
};
