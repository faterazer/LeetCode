#include <string>
using namespace std;

class Solution {
public:
    string makeFancyString(string s)
    {
        int cnt = 1, size = 1;
        for (size_t i = 1; i < s.size(); i++) {
            cnt = s[i] == s[i - 1] ? cnt + 1 : 1;
            if (cnt < 3)
                s[size++] = s[i];
        }
        s.resize(size);
        return s;
    }
};
