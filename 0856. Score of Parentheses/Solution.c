int scoreOfParentheses(char* s)
{
    int bal = 0, res = 0;
    for (int i = 0; s[i]; i++) {
        bal += s[i] == '(' ? 1 : -1;
        if (i > 0 && s[i - 1] == '(' && s[i] == ')')
            res += (1 << bal);
    }
    return res;
}
