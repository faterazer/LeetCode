#include <string>
using namespace std;

class Solution
{
public:
    int maxLengthBetweenEqualCharacters(string s)
    {
        int memo[26] = {0}, res = -1, size = s.size();
        for (int i = 0; i < size; i++) {
            if (memo[s[i] - 'a'])
                res = max(res, i - memo[s[i] - 'a']);
            else
                memo[s[i] - 'a'] = i + 1;
        }
        return res;
    }
};
