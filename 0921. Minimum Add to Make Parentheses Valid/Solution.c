int minAddToMakeValid(char* s)
{
    int res = 0, l = 0;
    for (int i = 0; s[i]; i++) {
        if (s[i] == '(')
            ++l;
        else if (l > 0)
            --l;
        else
            ++res;
    }
    return res + l;
}
