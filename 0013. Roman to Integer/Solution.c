int mapping(char c)
{
    switch (c) {
        case 'I':
            return 1;
            break;
        case 'V':
            return 5;
            break;
        case 'X':
            return 10;
            break;
        case 'L':
            return 50;
            break;
        case 'C':
            return 100;
            break;
        case 'D':
            return 500;
        case 'M':
            return 1000;
            break;
        default:
            return 0;
            break;
    }
}

int romanToInt(char *s)
{
    int ans = mapping(s[0]), prev, cur;
    for (int i = 1; s[i]; i++) {
        prev = mapping(s[i - 1]);
        cur = mapping(s[i]);
        if (prev < cur)
            ans -= prev * 2;
        ans += cur;
    }
    return ans;
}
