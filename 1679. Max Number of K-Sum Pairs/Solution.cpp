#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums, int k)
    {
        unordered_map<int, int> cnt;
        for (const int &e : nums)
            ++cnt[e];
        int res = 0;
        for (const auto &it : cnt) {
            int need = k - it.first;
            if (!cnt.count(need) || cnt[need] == 0)
                continue;
            if (it.first == need)
                res += it.second / 2;
            else
                res += min(it.second, cnt[need]);
            cnt[it.first] = cnt[need] = 0;
        }
        return res;
    }
};
