#include <ctype.h>
#include <memory.h>

char* shortestCompletingWord(char *licensePlate, char **words, int wordsSize)
{
    int hash[26] = {0};
    for (int i = 0; licensePlate[i]; i++)
        if (isalpha(licensePlate[i]))
            hash[tolower(licensePlate[i]) - 'a']++;
    int len = 16;   // words[i] 最长不超过15
    char *res = NULL;
    int counter[26] = {0};
    for (int i = 0; i < wordsSize; i++) {
        if (strlen(words[i]) >= len)
            continue;
        memset(counter, 0, sizeof(counter));
        char *word = words[i];
        for (int j = 0; word[j]; j++)
            counter[word[j] - 'a']++;
        int k = 0;
        while (k < 26 && counter[k] >= hash[k])
            k++;
        if (k == 26) {
            res = word;
            len = strlen(word);
        }
    }
    return res;
}
