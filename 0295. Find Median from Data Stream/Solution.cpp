#include <functional>
#include <queue>
using namespace std;

class MedianFinder {
public:
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (!max_heap.empty() && num <= max_heap.top()) {
            max_heap.emplace(num);
            if (max_heap.size() > min_heap.size() + 1) {
                min_heap.emplace(max_heap.top());
                max_heap.pop();
            }
        } else {
            min_heap.emplace(num);
            if (min_heap.size() > max_heap.size() + 1) {
                max_heap.emplace(min_heap.top());
                min_heap.pop();
            }
        }
    }

    double findMedian()
    {
        if (min_heap.size() > max_heap.size()) {
            return min_heap.top();
        } else if (max_heap.size() > min_heap.size()) {
            return max_heap.top();
        } else {
            return max_heap.top() * 0.5 + min_heap.top() * 0.5;
        }
    }

private:
    priority_queue<int, vector<int>, greater<int>> min_heap;
    priority_queue<int> max_heap;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
