int numDecodings(char* s)
{
    int a = 0, b = 1, c;
    for (int i = 0; s[i]; ++i) {
        c = 0;
        if (s[i] != '0')
            c = b;
        if (i > 0 && s[i - 1] != '0' && ((s[i - 1] - '0') * 10 + s[i] - '0') <= 26)
            c += a;
        a = b;
        b = c;
    }
    return c;
}
