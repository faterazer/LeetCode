#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int scoreOfParentheses(string s)
    {
        int bal = 0, res = 0;
        for (size_t i = 0; i < s.size(); i++) {
            bal += s[i] == '(' ? 1 : -1;
            if (s[i] == ')' && s[i - 1] == '(')
                res += 1 << bal;
        }
        return res;
    }
};
