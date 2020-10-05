#include <string>
using namespace std;

class Solution
{
public:
    bool validPalindrome(string s)
    {
        int l = 0, r = s.size() - 1;
        while (l < r && s[l] == s[r]) {
            l += 1;
            r -= 1;
        }
        return l >= r || isPalindrome(s, l + 1, r) || isPalindrome(s, l, r - 1);
    }
private:
    bool isPalindrome(string s, int low, int high)
    {
        for (; low < high; low++, high--)
            if (s[low] != s[high])
                return false;
        return true;
    }
};
