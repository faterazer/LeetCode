#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int removeStones(vector<vector<int>>& stones)
    {
        for (const vector<int> &stone : stones)
            uni(stone[0], ~stone[1]);
        return stones.size() - islands;
    }

private:
    int find(int x) {
        if (!uf.count(x)) {
            uf[x] = x;
            islands++;
        }
        if (x != uf[x])
            uf[x] = find(uf[x]);
        return uf[x];
    }

    void uni(int x, int y) {
        int root_x = find(x), root_y = find(y);
        if (root_x != root_y) {
            uf[root_x] = root_y;
            islands--;
        }
    }

    unordered_map<int, int> uf;
    int islands = 0;
};
