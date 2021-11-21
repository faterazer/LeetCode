#include <math.h>

struct Node {
    int val;
    int numChildren;
    struct Node** children;
};

int maxDepth(struct Node* root)
{
    if (!root)
        return 0;
    int depth = 0;
    for (int i = 0; i < root->numChildren; i++)
        depth = fmax(depth, maxDepth(root->children[i]));
    return depth + 1;
}
