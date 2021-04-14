char* modifyString(char *s)
{
    char sentinel = 'a' - 1, lc, rc;
    for (int i = 0; s[i]; i++) {
        if (s[i] != '?')
            continue;
        lc = i == 0 ? sentinel : s[i - 1];
        rc = s[i + 1] == '\0' || s[i + 1] == '?' ? sentinel : s[i + 1];
        for (s[i] = 'a'; s[i] <= 'z' && (s[i] == lc || s[i] == rc); s[i]++)
            ;
    }
    return s;
}
