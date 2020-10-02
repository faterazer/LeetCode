#include <queue>
using namespace std;

class RecentCounter
{
public:
    RecentCounter()
    {
    }

    int ping(int t)
    {
        timeQ.emplace(t);
        while (t - timeQ.front() > 3000)
            timeQ.pop();
        return timeQ.size();
    }

private:
    queue<int> timeQ;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
