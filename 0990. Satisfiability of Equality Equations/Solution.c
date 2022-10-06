#include <stdbool.h>

int findRoot(int tree[], int x)
{
    if (tree[x] == x)
        return x;
    tree[x] = findRoot(tree, tree[x]);
    return tree[x];
}

bool equationsPossible(char** equations, int equationsSize)
{
    int tree[26];
    for (int i = 0; i < 26; i++)
        tree[i] = i;

    for (int i = 0; i < equationsSize; i++) {
        int a = equations[i][0] - 'a', b = equations[i][3] - 'a';
        if (equations[i][1] == '=') {
            int root_a = findRoot(tree, a), root_b = findRoot(tree, b);
            tree[root_a] = root_b;
        }
    }
    for (int i = 0; i < equationsSize; i++) {
        int a = equations[i][0] - 'a', b = equations[i][3] - 'a';
        int root_a = findRoot(tree, a), root_b = findRoot(tree, b);
        if (equations[i][1] == '!' && root_a == root_b)
            return false;
    }
    return true;
}
