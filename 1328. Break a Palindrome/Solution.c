#include <string.h>

char* breakPalindrome(char* palindrome)
{
    int n = strlen(palindrome);
    if (n < 2)
        return "";
    for (int i = 0; i < n / 2; i++) {
        if (palindrome[i] != 'a') {
            palindrome[i] = 'a';
            return palindrome;
        }
    }
    palindrome[n - 1] = 'b';
    return palindrome;
}
