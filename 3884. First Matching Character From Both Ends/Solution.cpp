#include <string>
using namespace std;

class Solution {
public:
    int firstMatchingIndex(string s)
    {
        int n = s.size(), m = (n + 1) / 2;
        for (int i = 0; i < m; ++i)
            if (s[i] == s[n - 1 - i])
                return i;
        return -1;
    }
};
