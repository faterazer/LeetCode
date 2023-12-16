#include <map>
using namespace std;

class CountIntervals {
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

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */
