#include <functional>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr)
    {
        vector<int> DSU(26, -1);

        function<int(int)> find = [&](int x) -> int {
            if (DSU[x] < 0)
                return x;
            int root = find(DSU[x]);
            DSU[x] = root;
            return root;
        };

        function<void(int, int)> unionSets = [&](int x, int y) -> void {
            int root_x = find(x);
            int root_y = find(y);
            if (root_x < root_y)
                DSU[root_y] = root_x;
            else if (root_x > root_y)
                DSU[root_x] = root_y;
        };

        int n = s1.size();
        for (int i = 0; i < n; ++i)
            unionSets(s1[i] - 'a', s2[i] - 'a');

        string ans;
        for (char c : baseStr) {
            int x = c - 'a';
            ans.push_back(find(x) + 'a');
        }
        return ans;
    }
};
