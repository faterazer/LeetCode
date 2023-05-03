char* lastSubstring(char* s)
{
    int i = 0;
    for (int j = 1, k = 0; s[j + k];) {
        if (s[i + k] == s[j + k])
            k++;
        else if (s[i + k] < s[j + k]) {
            i += k + 1;
            k = 0;
            if (i >= j)
                j = i + 1;
        } else {
            j += k + 1;
            k = 0;
        }
    }
    return s + i;
}
