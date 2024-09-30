#include <queue>
#include <vector>
using namespace std;

class SeatManager {
public:
    SeatManager(int n)
    {
    }

    int reserve()
    {
        if (available.empty())
            return ++seat;
        int res = available.top();
        available.pop();
        return res;
    }

    void unreserve(int seatNumber)
    {
        available.emplace(seatNumber);
    }

private:
    priority_queue<int, vector<int>, greater<>> available;
    int seat = 0;
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
