#include <string>
#include <tuple>
#include <vector>
using namespace std;

class Solution {
public:
    int numDecodings(string s)
    {
        int a = 0, b = 1, c;
        for (size_t i = 0; i < s.size(); ++i) {
            c = 0;
            if (s[i] != '0')
                c = b;
            if (i > 0 && s[i - 1] != '0' && (s[i - 1] - '0') * 10 + (s[i] - '0') <= 26)
                c += a;
            tie(a, b) = { b, c };
        }
        return c;
    }
};
