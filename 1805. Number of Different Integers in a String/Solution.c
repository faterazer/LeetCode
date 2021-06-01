#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    bool is_end;
    struct Node *children[10];
} Node;

Node *getNode(void)
{
    Node *p = (Node*)malloc(sizeof(Node));
    for (int i = 0; i < 10; i++)
        p->children[i] = NULL;
    p->is_end = false;
    return p;
}

void insert(Node *root, char *s)
{
    for (; *s; s++) {
        if (!root->children[*s - '0'])
            root->children[*s - '0'] = getNode();
        root = root->children[*s - '0'];
    }
    root->is_end = true;
}

int countLeaves(Node *root)
{
    if (!root)
        return 0;
    int res = root->is_end == true;
    for (int i = 0; i < 10; i++)
        res += countLeaves(root->children[i]);
    return res;
}

void destory(Node *root)
{
    if (!root)
        return;
    for (int i = 0; i < 10; i++)
        destory(root->children[i]);
    free(root);
}

int numDifferentIntegers(char *word)
{
    char buff[1024];
    Node *root = getNode();
    int i, j;
    for (i = 0, j = 0; word[j]; j++) {
        if (isdigit(word[j])) {
            if (i < j && word[i] == '0')
                i++;
        } else {
            if (i < j) {
                strncpy(buff, word + i, j - i);
                buff[j - i] = '\0';
                insert(root, buff);
            }
            i = j + 1;
        }
    }
    if (i < j) {
        strcpy(buff, word + i);
        insert(root, buff);
    }
    int res = countLeaves(root);
    destory(root);
    return res;
}
