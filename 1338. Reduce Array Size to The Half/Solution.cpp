#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int minSetSize(vector<int>& arr)
    {
        unordered_map<int, int> cnt;
        for (const int& x : arr)
            ++cnt[x];
        vector<int> buff;
        for (const auto& it : cnt)
            buff.emplace_back(it.second);
        sort(buff.begin(), buff.end(), greater<int>());
        int res = 0, len = arr.size(), half = len / 2;
        for (const int& freq : buff) {
            len -= freq;
            ++res;
            if (len <= half)
                return res;
        }
        return res;
    }
};
