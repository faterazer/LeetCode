#include <string>
using namespace std;

class Solution {
public:
    int countHomogenous(string s)
    {
        int P = 1e9 + 7, res = 0, cnt = 0;
        char last_c = 0;
        for (const char& c : s) {
            cnt = c == last_c ? cnt + 1 : 1;
            res = (res + cnt) % P;
            last_c = c;
        }
        return res;
    }
};
