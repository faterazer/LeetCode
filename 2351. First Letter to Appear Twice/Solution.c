char repeatedCharacter(char* s)
{
    unsigned seen = 0;
    while (*s) {
        int offset = *s - 'a';
        if (seen & (1 << offset))
            return *s;
        seen |= 1 << offset;
        s++;
    }
    return 0;
}
