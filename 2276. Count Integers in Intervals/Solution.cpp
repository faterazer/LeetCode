#include <map>
using namespace std;

class CountIntervals_MK1 {
public:
    CountIntervals()
    {
    }

    void add(int left, int right)
    {
        for (auto it = tree.lower_bound(left); it != tree.end() && it->second <= right; tree.erase(it++)) {
            left = min(left, it->second);
            right = max(right, it->first);
            cnt -= it->first - it->second + 1;
        }
        tree[right] = left;
        cnt += right - left + 1;
    }

    int count()
    {
        return cnt;
    }

private:
    map<int, int> tree;
    int cnt = 0;
};

class CountIntervals_MK2 {
public:
    CountIntervals_MK2(int left = 0, int right = 1e9)
        : l(left)
        , r(right)
    {
    }

    void add(int left, int right)
    {
        if (cnt == r - l + 1)
            return;

        if (left <= l && r <= right) {
            cnt = r - l + 1;
            return;
        }

        int m = l + ((r - l) >> 1);
        if (!lchild)
            lchild = new CountIntervals_MK2(l, m);
        if (!rchild)
            rchild = new CountIntervals_MK2(m + 1, r);
        if (left <= m)
            lchild->add(left, right);
        if (right > m)
            rchild->add(left, right);
        cnt = lchild->count() + rchild->count();
    }

    int count()
    {
        return cnt;
    }

private:
    int l = 0, r = 0, cnt = 0;
    CountIntervals *lchild = nullptr, *rchild = nullptr;
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */
