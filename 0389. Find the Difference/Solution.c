// XOR
char findTheDifference(char *s, char *t)
{
    char c = 0;
    for (int i = 0; s[i]; i++)
        c ^= s[i];
    for (int i = 0; t[i]; i++)
        c ^= t[i];
    return c;
}
