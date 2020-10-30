#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct TireNode
{
    bool isWord;
    struct TireNode *children[26];
} TireNode;

TireNode* createTireTree(void)
{
    TireNode *p = (TireNode*)malloc(sizeof(TireNode));
    p->isWord = false;
    for (int i = 0; i < sizeof(p->children) / sizeof(TireNode*); i++)
        p->children[i] = NULL;
    return p;
}

void tireTreeInsert(TireNode *root, char *word)
{
    int index;
    for (int i = 0; word[i]; i++) {
        index = word[i] - 'a';
        if (!root->children[index])
            root->children[index] = createTireTree();
        root = root->children[index];
    }
    root->isWord = true;
}

void dfs(TireNode *root, char *prefix, char *longestWord)
{
    bool isLeaf = true;
    for (int i = 0; i < sizeof(root->children) / sizeof(root); i++) {
        if (!root->children[i] || !root->children[i]->isWord)
            continue;
        isLeaf = false;
        int n = strlen(prefix);
        prefix[n] = 'a' + i;
        prefix[n + 1] = '\0';
        dfs(root->children[i], prefix, longestWord);
        prefix[n] = '\0';
    }
    if (isLeaf && (strlen(prefix) > strlen(longestWord) || strcmp(prefix, longestWord) < 0))
        strcpy(longestWord, prefix);
}

char* longestWord(char **words, int wordsSize)
{
    TireNode *tire = createTireTree();
    for (int i = 0; i < wordsSize; i++)
        tireTreeInsert(tire, words[i]);

    char buff[32] = {0}, prefix[32] = {0};
    dfs(tire, prefix, buff);
    char *ret = (char*)malloc(sizeof(char) * (strlen(buff) + 1));
    strcpy(ret, buff);
    return ret;
}
