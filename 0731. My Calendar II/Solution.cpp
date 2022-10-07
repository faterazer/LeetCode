#include <unordered_map>
using namespace std;

class MyCalendarTwo {
public:
    MyCalendarTwo()
    {
    }

    bool book(int start, int end)
    {
        update(start, end - 1, 1, 1, 0, 1e9);
        if (tree[1].first > 2) {
            update(start, end - 1, -1, 1, 0, 1e9);
            return false;
        }
        return true;
    }

private:
    void update(int start, int end, int val, int idx, int l, int r)
    {
        if (r < start || end < l)
            return;
        if (start <= l && r <= end) {
            tree[idx].first += val;
            tree[idx].second += val;
        } else {
            int m = l + ((r - l) >> 1);
            update(start, end, val, idx * 2, l, m);
            update(start, end, val, idx * 2 + 1, m + 1, r);
            tree[idx].first = tree[idx].second + max(tree[2 * idx].first, tree[2 * idx + 1].first);
        }
    }

    unordered_map<int, pair<int, int>> tree;
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
