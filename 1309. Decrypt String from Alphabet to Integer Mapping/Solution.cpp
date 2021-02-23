#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
    string freqAlphabets(string s)
    {
        string res;
        int i = s.size() - 1;
        char base = 'a' - 1;
        while (i >= 0) {
            if (s[i] == '#') {
                res.push_back((s[i - 2] - '0') * 10 + (s[i - 1] - '0') + base);
                i -= 3;
            }
            else {
                res.push_back(s[i] - '0' + base);
                i--;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
