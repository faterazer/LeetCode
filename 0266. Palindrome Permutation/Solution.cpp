#include <string>
using namespace std;

class Solution {
public:
    bool canPermutePalindrome(string s)
    {
        int cnt[26] = { 0 };
        for (char c : s)
            cnt[c - 'a']++;

        int odds = 0;
        for (int i = 0; i < 26; i++)
            if ((cnt[i] & 1) && ++odds > 1)
                return false;
        return true;
    }
};
