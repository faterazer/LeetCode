#include <queue>
#include <vector>
using namespace std;

class KthLargest
{
public:
    KthLargest(int k, vector<int> &nums) : limit(k), min_heap(nums.begin(), nums.end())
    {
        while (min_heap.size() > limit)
            min_heap.pop();
    }

    int add(int val)
    {
        min_heap.emplace(val);
        if (min_heap.size() > limit)
            min_heap.pop();
        return min_heap.top();
    }

private:
    size_t limit;
    priority_queue<int, vector<int>, greater<int>> min_heap;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
