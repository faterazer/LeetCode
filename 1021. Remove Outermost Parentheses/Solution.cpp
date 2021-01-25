#include <string>
using namespace std;

class Solution
{
public:
    string removeOuterParentheses(string S)
    {
        string res;
        int left = 0;
        for (const char &ch : S)
            if ((ch == '(' && left++ > 0) || (ch == ')' && left-- > 1))
                res.push_back(ch);
        return res;
    }
};
