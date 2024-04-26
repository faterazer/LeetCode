#include <ranges>
#include <unordered_map>
#include <vector>
using namespace std;

class SnapshotArray {
public:
    SnapshotArray(int length)
    {
    }

    void set(int index, int val)
    {
        history[index].emplace_back(cur_snap_id, val);
    }

    int snap()
    {
        return cur_snap_id++;
    }

    int get(int index, int snap_id)
    {
        vector<pair<int, int>>& h = history[index];
        int i = ranges::lower_bound(h, make_pair(snap_id + 1, 0)) - h.begin() - 1;
        return i >= 0 ? h[i].second : 0;
    }

private:
    int cur_snap_id = 0;
    unordered_map<int, vector<pair<int, int>>> history;
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */