#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(const string &s)
    {
        unordered_map<char, int> dict;
        int beg = -1, res = 0;
        for (int i = 0; i < s.size(); i++) {
            auto it = dict.find(s[i]);
            if (it != dict.end() && it->second > beg)
                beg = it->second;
            dict[s[i]] = i;
            res = max(res, i - beg);
        }
        return res;
    }
};
