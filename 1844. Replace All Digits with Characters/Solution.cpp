#include <string>
using namespace std;

class Solution
{
public:
    string replaceDigits(string s)
    {
        for (size_t i = 1; i < s.size(); i += 2)
            s[i] += s[i - 1] - '0';
        return s;
    }
};
