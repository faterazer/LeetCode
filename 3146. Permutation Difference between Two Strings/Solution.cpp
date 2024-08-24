#include <cmath>
#include <string>
using namespace std;

class Solution {
public:
    int findPermutationDifference(string s, string t)
    {
        int ch2idx[26], n = s.size();
        for (int i = 0; i < n; i++)
            ch2idx[s[i] - 'a'] = i;

        int res = 0;
        for (int i = 0; i < n; i++)
            res += abs(ch2idx[t[i] - 'a'] - i);
        return res;
    }
};
