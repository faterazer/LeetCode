#include <string.h>

int countMatches(char ***items, int itemsSize, int *itemsColSize, char *ruleKey, char *ruleValue)
{
    char *keylist[]={"type", "color", "name"};
    int len = 3, res = 0, key;
    for (key = 0; key < len && strcmp(keylist[key], ruleKey) != 0; key++)
        ;
    for (int i = 0; i < itemsSize; i++)
        if (strcmp(items[i][key], ruleValue) == 0)
            res++;
    return res;
}
