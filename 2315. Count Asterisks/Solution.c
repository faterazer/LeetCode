int countAsterisks(char* s)
{
    int res = 0, bars = 0;
    for (int i = 0; s[i]; i++) {
        if (s[i] == '*' && bars % 2 == 0)
            ++res;
        else if (s[i] == '|')
            ++bars;
    }
    return res;
}
