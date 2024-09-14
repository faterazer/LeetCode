#include <string>
using namespace std;

class Solution {
public:
    string removeStars(string s)
    {
        int tp = 0;
        for (char c : s) {
            if (c != '*')
                s[tp++] = c;
            else
                --tp;
        }
        s.resize(tp);
        return s;
    }
};
