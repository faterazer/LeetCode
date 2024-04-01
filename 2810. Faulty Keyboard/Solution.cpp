#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    string finalString(string s)
    {
        int len = 1;
        for (size_t i = 1; i < s.size(); i++) {
            if (s[i] != 'i')
                s[len++] = s[i];
            else
                reverse(s.begin(), s.begin() + len);
        }
        s.resize(len);
        return s;
    }
};
