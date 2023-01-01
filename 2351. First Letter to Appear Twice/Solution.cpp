#include <string>
using namespace std;

class Solution {
public:
    char repeatedCharacter(string s)
    {
        unsigned seen = 0;
        for (const char& c : s) {
            int offset = c - 'a';
            if (seen & (1 << offset))
                return c;
            seen |= 1 << offset;
        }
        return 0;
    }
};
