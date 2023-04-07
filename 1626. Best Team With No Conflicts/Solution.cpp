#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages)
    {
        int n = scores.size();
        vector<int> idxs(n);
        iota(idxs.begin(), idxs.end(), 0);
        sort(idxs.begin(), idxs.end(), [&](const int& left, const int& right) {
            return scores[left] != scores[right] ? scores[left] < scores[right] : ages[left] < ages[right];
        });

        vector<int> tree(1001, 0);
        for (const int& i : idxs)
            update(tree, ages[i], query(tree, ages[i]) + scores[i]);
        return query(tree, 1000);
    }

private:
    int lowbit(int x)
    {
        return x & -x;
    }

    void update(vector<int>& tree, size_t idx, int val)
    {
        for (; idx < tree.size(); idx += lowbit(idx))
            tree[idx] = max(tree[idx], val);
    }

    int query(vector<int>& tree, size_t idx)
    {
        int res = 0;
        for (; idx > 0; idx -= lowbit(idx))
            res = max(res, tree[idx]);
        return res;
    }
};
