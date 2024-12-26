#include <string>
using namespace std;

class Solution {
public:
    bool isSubstringPresent(string s)
    {
        unsigned seen[26] = { 0 };
        for (size_t i = 1; i < s.size(); ++i) {
            unsigned x = s[i - 1] - 'a', y = s[i] - 'a';
            seen[x] |= 1 << y;
            if (seen[y] >> x & 1)
                return true;
        }
        return false;
    }
};
