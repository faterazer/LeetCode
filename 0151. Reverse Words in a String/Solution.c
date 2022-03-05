void reverse(char *s, int low, int high)
{
    char tmp;
    for (int i = low, j = high; i < j; i++, j--) {
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }
}

char* reverseWords(char* s)
{
    if (!s[0])
        return s;
    int size = 0;
    for (int i = 0; s[i];) {
        while (s[i] && s[i] == ' ')
            ++i;
        while (s[i] && s[i] != ' ')
            s[size++] = s[i++];
        if (s[i])
            s[size++] = ' ';
    }
    if (s[size - 1] == ' ')
        s[--size] = '\0';
    else
        s[size] = '\0';
    reverse(s, 0, size - 1);
    int low = 0, high = 0;
    for (; high < size; ++high) {
        while (high < size && s[high] != ' ')
            ++high;
        reverse(s, low, high - 1);
        low = high + 1;
    }
    return s;
}
