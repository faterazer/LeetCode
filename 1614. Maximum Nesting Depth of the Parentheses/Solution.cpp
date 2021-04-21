#include <string>
using namespace std;

class Solution
{
public:
    int maxDepth(string s)
    {
        int lp = 0, res = 0;
        for (const char &ch : s) {
            if (ch == '(')
                res = max(res, ++lp);
            else if (ch == ')')
                lp--;
        }
        return res;
    }
};
