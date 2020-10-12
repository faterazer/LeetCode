#define min(a, b) ((a < b) ? (a) : (b))

int countBinarySubstrings(char *s)
{
    int lastCnt = 0, cnt = 1, ans = 0;
    for (int i = 1; s[i]; i++) {
        if (s[i] != s[i - 1]) {
            ans += min(lastCnt, cnt);
            lastCnt = cnt;
            cnt = 0;
        }
        cnt += 1;
    }
    return ans + min(lastCnt, cnt);
}
