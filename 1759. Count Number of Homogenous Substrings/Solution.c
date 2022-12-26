int countHomogenous(char* s)
{
    int P = 1e9 + 7, res = 0, cnt = 0;
    char last_c = 0;
    for (int i = 0; s[i]; i++) {
        cnt = s[i] == last_c ? cnt + 1 : 1;
        res = (res + cnt) % P;
        last_c = s[i];
    }
    return res;
}
