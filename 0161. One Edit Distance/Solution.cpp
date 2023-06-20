#include <string>
using namespace std;

class Solution {
public:
    bool isOneEditDistance(string s, string t)
    {
        if (s.size() < t.size())
            return isOneEditDistance(t, s);
        if (s.size() - t.size() > 2)
            return false;

        size_t i, j;
        for (i = 0, j = 0; i < s.size() && j < t.size(); i++, j++)
            if (s[i] != t[j])
                return s.substr(i + 1) == t.substr(j + 1) || s.substr(i + 1) == t.substr(j);
        return i == s.size() - 1;
    }
};
