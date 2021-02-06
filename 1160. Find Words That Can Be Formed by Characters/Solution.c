#include <memory.h>

int countCharacters(char **words, int wordsSize, char *chars)
{
    int res = 0;
    char table[26] = {0}, tmp_table[26];
    for (int i = 0; chars[i]; i++)
        table[chars[i] - 'a']++;
    for (int i = 0; i < wordsSize; i++) {
        memset(tmp_table, 0, sizeof(char) * 26);
        int j = 0;
        for (; words[i][j]; j++)
            if (++tmp_table[words[i][j] - 'a'] > table[words[i][j] - 'a'])
                break;
        if (!words[i][j])
            res += j;
    }
    return res;
}
