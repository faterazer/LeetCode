#include <queue>
#include <unordered_set>
using namespace std;

class SmallestInfiniteSet {
public:
    SmallestInfiniteSet()
    {
    }

    int popSmallest()
    {
        if (!min_heap.empty()) {
            int res = min_heap.top();
            min_heap.pop();
            removed.emplace(res);
            return res;
        } else {
            removed.emplace(bound++);
            return bound - 1;
        }
    }

    void addBack(int num)
    {
        if (removed.count(num)) {
            removed.erase(num);
            min_heap.emplace(num);
        }
    }

private:
    priority_queue<int, vector<int>, greater<int>> min_heap;
    int bound = 1;
    unordered_set<int> removed;
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
