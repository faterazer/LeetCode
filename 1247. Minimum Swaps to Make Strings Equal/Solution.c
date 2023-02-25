int minimumSwap(char* s1, char* s2)
{
    int xy = 0, yx = 0;
    for (int i = 0; s1[i]; i++) {
        if (s1[i] == s2[i])
            continue;
        else if (s1[i] == 'x')
            ++xy;
        else
            ++yx;
    }
    if (xy % 2 != yx % 2)
        return -1;
    return xy / 2 + yx / 2 + xy % 2 + yx % 2;
}
