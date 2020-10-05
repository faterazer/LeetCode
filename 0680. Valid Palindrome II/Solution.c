#include <stdbool.h>
#include <string.h>

bool isPalindrome(char *s, int low, int high)
{
    for (; low < high; low++, high--)
        if (s[low] != s[high])
            return false;
    return true;
}

bool validPalindrome(char *s)
{
    int l = 0, r = strlen(s) - 1;
    while (l < r && s[l] == s[r]) {
        l += 1;
        r -= 1;
    }
    return l >= s || isPalindrome(s, l + 1, r) || isPalindrome(s, l, r - 1);
}
