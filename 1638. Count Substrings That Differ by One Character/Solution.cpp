#include <string>
using namespace std;

class Solution {
public:
    int countSubstrings(string s, string t)
    {
        int res = 0, sn = s.size(), tn = t.size();
        for (int i = 0; i < sn; i++)
            res += helper(s, t, i, 0);
        for (int j = 1; j < tn; j++)
            res += helper(s, t, 0, j);
        return res;
    }

private:
    int helper(const string& s, const string& t, int i, int j)
    {
        int res = 0, pre = 0, cur = 0;
        for (int sn = s.length(), tn = t.size(); i < sn && j < tn; i++, j++) {
            cur++;
            if (s[i] != t[j]) {
                pre = cur;
                cur = 0;
            }
            res += pre;
        }
        return res;
    }
};
