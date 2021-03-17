#include <cctype>
#include <queue>
#include <string>
using namespace std;

class Solution
{
public:
    string reformat(string s)
    {
        int n1 = 0, n2 = 0;     // n1 计数字母，n2计数数字
        for (const char &ch : s) {
            if (isalpha(ch))
                n1++;
            else
                n2++;
        }
        if (abs(n1 - n2) > 1)
            return "";
        if (n1 > n2) {
            n1 = 0;
            n2 = 1;
        }
        else {
            n1 = 1;
            n2 = 0;
        }
        string res;
        res.resize(s.size());
        for (const char &ch : s) {
            if (isalpha(ch)) {
                res[n1] = ch;
                n1 += 2;
            }
            else {
                res[n2] = ch;
                n2 += 2;
            }
        }
        return res;
    }
};
