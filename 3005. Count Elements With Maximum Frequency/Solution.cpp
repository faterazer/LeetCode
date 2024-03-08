#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums)
    {
        int res = 0, max_freq = 0;
        unordered_map<int, int> cnt;
        for (int x : nums) {
            int freq = ++cnt[x];
            if (freq > max_freq)
                res = max_freq = freq;
            else if (freq == max_freq)
                res += freq;
        }
        return res;
    }
};
