int countConsistentStrings(char *allowed, char **words, int wordsSize)
{
    int table[26] = {0}, res = wordsSize;
    for (int i = 0; allowed[i]; i++)
        table[allowed[i] - 'a'] = 1;
    for (int i = 0; i < wordsSize; i++) {
        for (int j = 0; words[i][j]; j++) {
            if (!table[words[i][j] - 'a']) {
                res--;
                break;
            }
        }
    }
    return res;
}
