int balancedStringSplit(char *s)
{
    int cnt = 0, ans = 0;
    for (int i = 0; s[i]; i++) {
        cnt += s[i] == 'L' ? 1 : -1;
        ans += cnt == 0;
    }
    return ans;
}
