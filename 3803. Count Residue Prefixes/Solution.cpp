#include <bit>
#include <string>
using namespace std;

class Solution {
public:
    int residuePrefixes(string s)
    {
        unsigned st = 0;
        int result = 0, n = s.size();
        for (int i = 0; i < n; ++i) {
            st |= 1 << (s[i] - 'a');
            int x = popcount(st);
            if (x == (i + 1) % 3)
                ++result;
            if (x >= 3)
                break;
        }
        return result;
    }
};
