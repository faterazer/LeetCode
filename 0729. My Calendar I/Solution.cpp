#include <set>
using namespace std;

class MyCalendar {
public:
    MyCalendar()
    {
    }

    bool book(int start, int end)
    {
        auto it = booked.lower_bound({ start, start });
        if (it == booked.end() || it->second >= end) {
            booked.emplace(end, start);
            return true;
        }
        return false;
    }

private:
    set<pair<int, int>> booked;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
