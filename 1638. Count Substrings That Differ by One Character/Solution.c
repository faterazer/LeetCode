int helper(char* s, char* t, int i, int j)
{
    int res = 0, pre = 0, cur = 0;
    for (; s[i] && t[j]; i++, j++) {
        ++cur;
        if (s[i] != t[j]) {
            pre = cur;
            cur = 0;
        }
        res += pre;
    }
    return res;
}

int countSubstrings(char* s, char* t)
{
    int res = 0;
    for (int i = 0; t[i]; i++)
        res += helper(s, t, 0, i);
    for (int i = 1; s[i]; i++)
        res += helper(s, t, i, 0);
    return res;
}
