#include <functional>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool equationsPossible(vector<string>& equations)
    {
        vector<int> tree(26);
        for (int i = 0; i < 26; ++i)
            tree[i] = i;
        function<int(int)> findRoot = [&](int x) -> int {
            if (tree[x] == x)
                return x;
            tree[x] = findRoot(tree[x]);
            return tree[x];
        };
        for (const string& equation : equations) {
            int a = equation[0] - 'a', b = equation[3] - 'a';
            if (equation[1] == '=')
                tree[findRoot(a)] = findRoot(b);
        }
        for (const string& equation : equations) {
            int a = equation[0] - 'a', b = equation[3] - 'a';
            if (equation[1] == '!' && findRoot(a) == findRoot(b))
                return false;
        }
        return true;
    }
};
