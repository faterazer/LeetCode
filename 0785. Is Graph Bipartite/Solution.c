#include <stdbool.h>

int findRoot(int* tree, int x)
{
    if (tree[x] == -1)
        return x;
    int res = findRoot(tree, tree[x]);
    tree[x] = res;
    return res;
}

bool isBipartite(int** graph, int graphSize, int* graphColSize)
{
    int tree[graphSize];
    for (int i = 0; i < graphSize; ++i)
        tree[i] = -1;
    for (int i = 0; i < graphSize; ++i) {
        if (graphColSize[i] == 0)
            continue;
        int root1 = findRoot(tree, i), root2 = findRoot(tree, graph[i][0]);
        if (root1 == root2)
            return false;
        for (int j = 1; j < graphColSize[i]; ++j) {
            int root = findRoot(tree, graph[i][j]);
            if (root1 == root)
                return false;
            if (root2 != root)
                tree[root] = root2;
        }
    }
    return true;
}
