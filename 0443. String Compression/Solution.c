void reverse(char* s, int l, int r)
{
    char tmp;
    while (l < r) {
        tmp = s[l];
        s[l++] = s[r];
        s[r--] = tmp;
    }
}

int compress(char* chars, int charsSize)
{
    int i = 0, idx = 0;
    while (i < charsSize) {
        char ch = chars[i];
        int cnt = 0;
        while (i < charsSize && chars[i] == ch) {
            ++i;
            ++cnt;
        }

        chars[idx++] = ch;
        if (cnt > 1) {
            int j = idx;
            while (cnt) {
                chars[idx++] = cnt % 10 + '0';
                cnt /= 10;
            }
            reverse(chars, j, idx - 1);
        }
    }
    charsSize = idx;
    return idx;
}
