#include <algorithm>
#include <sstream>
#include <string>
using namespace std;

class Solution
{
public:
    string reverseWords_MK1(string s)
    {
        if (s.empty())
            return "";
        stringstream sentence(s);
        string word, ret;
        while (sentence >> word) {
            reverse(word.begin(), word.end());
            ret += word + " ";
        }
        ret.pop_back();
        return ret;
    }

    string reverseWords_MK2(string s)
    {
        size_t beg = 0;
        for (size_t i = 0; i <= s.size(); i++) {
            if (i == s.size() || isspace(s[i])) {
                reverse(s.begin() + beg, s.begin() + i);
                beg = i + 1;
            }
        }
        return s;
    }
};
