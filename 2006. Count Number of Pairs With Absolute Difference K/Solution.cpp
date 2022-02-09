#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int countKDifference(vector<int>& nums, int k)
    {
        unordered_map<int, int> counter;
        for (const int &e : nums)
            counter[e]++;

        int res = 0;
        for (const auto &it : counter) {
            if (counter.count(it.first + k))
                res += it.second * counter[it.first + k];
        }
        return res;
    }
};
