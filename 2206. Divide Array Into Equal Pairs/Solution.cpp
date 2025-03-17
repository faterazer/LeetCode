#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    bool divideArray(vector<int>& nums)
    {
        unordered_map<int, int> cnt;
        for (int x : nums)
            ++cnt[x];

        return all_of(cnt.cbegin(), cnt.cend(), [](const pair<int, int>& p) { return p.second % 2 == 0; });
    }
};