#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int rearrangeCharacters(string s, string target)
    {
        unordered_map<char, int> cnt, target_cnt;
        for (const char& c : s)
            cnt[c]++;
        for (const char& c : target)
            target_cnt[c]++;

        int res = s.size();
        for (const auto& it : target_cnt)
            res = min(res, cnt[it.first] / it.second);
        return res;
    }
};
