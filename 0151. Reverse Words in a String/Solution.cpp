#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    string reverseWords(string s)
    {
        int n = 0;
        for (size_t i = 0; i < s.size();) {
            while (i < s.size() && s[i] == ' ')
                ++i;
            while (i < s.size() && s[i] != ' ')
                s[n++] = s[i++];
            if (i < s.size())
                s[n++] = ' ';
        }
        if (s[n - 1] == ' ')
            --n;
        reverse(s.begin(), s.begin() + n);
        int low = 0, high = 0;
        for (; high < n; ++high) {
            low = high;
            while (high < n && s[high] != ' ')
                ++high;
            reverse(s.begin() + low, s.begin() + high);
        }
        s.erase(s.begin() + n, s.end());
        return s;
    }
};
