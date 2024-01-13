#include <map>
#include <string>
using namespace std;

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit)
    {
        map<char, int> cnt;
        for (char c : s)
            cnt[c]++;

        string res;
        for (auto it = cnt.rbegin(); it != cnt.rend();) {
            char c = it->first;
            int n = it->second;
            it++;
            while (n > repeatLimit && it != cnt.rend()) {
                res += string(repeatLimit, c) + it->first;
                n -= repeatLimit;
                if (--it->second == 0) {
                    cnt.erase((it++).base());
                }
            }
            res += string(min(n, repeatLimit), c);
        }
        return res;
    }
};
