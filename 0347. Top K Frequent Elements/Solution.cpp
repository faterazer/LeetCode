#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        unordered_map<int, int> cnt;
        for (const int& e : nums)
            ++cnt[e];
        vector<pair<int, int>> buff(cnt.begin(), cnt.end());
        nth_element(buff.begin(), buff.begin() + k, buff.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second;
        });
        vector<int> res(k);
        for (int i = 0; i < k; ++i)
            res[i] = buff[i].first;
        return res;
    }
};
