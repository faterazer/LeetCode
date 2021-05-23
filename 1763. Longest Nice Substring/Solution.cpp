#include <cctype>
#include <string>
using namespace std;

class Solution
{
public:
    string longestNiceSubstring(const string &s)
    {
        unsigned upper = 0, lower = 0, unboth;
        for (const char &c : s) {
            if (isupper(c))
                upper |= 1 << (c - 'A');
            else
                lower |= 1 << (c - 'a');
        }
        unboth = upper ^ lower;
        for (size_t i = 0; i < s.size(); i++) {
            if ((unboth >> (tolower(s[i]) - 'a')) & 1) {
                string left = longestNiceSubstring(s.substr(0, i));
                string right = longestNiceSubstring(s.substr(i + 1));
                return left.size() >= right.size() ? left : right;
            }
        }
        return s;
    }
};
