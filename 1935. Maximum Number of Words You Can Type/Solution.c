int canBeTypedWords(char *text, char *brokenLetters)
{
    int hash[26] = {0}, res = 0, hasBroken = 1;
    for (int i = 0; brokenLetters[i]; i++)
        hash[brokenLetters[i] - 'a'] = 1;
    for (int i = 0; text[i]; i++) {
        if (text[i] == ' ') {
            res += hasBroken;
            hasBroken = 1;
        } else if (hash[text[i] - 'a'])
            hasBroken = 0;
    }
    return res + hasBroken;
}
