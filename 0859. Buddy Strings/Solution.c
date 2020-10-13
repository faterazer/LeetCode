#include <stdbool.h>
#include <string.h>

bool buddyStrings(char *A, char *B)
{
    size_t aLen = strlen(A), bLen = strlen(B);
    if (aLen < 2 || bLen < 2 || aLen != bLen)
        return false;
    int hash[26] = {0};
    int buff[2] = {'\0'};
    int bftp = 0;
    for (size_t i = 0; i < aLen; i++) {
        hash[A[i] - 'a']++;
        if (A[i] != B[i]) {
            if (bftp == 2)
                return false;
            buff[bftp++] = i;
        }
    }
    if (bftp == 0) {
        for (int i = 0; i < 26; i++)
            if (hash[i] > 1)
                return true;
        return false;
    }
    else if (bftp == 1)
        return false;
    else
        return A[buff[1]] == B[buff[0]] && A[buff[0]] == B[buff[1]];
}
