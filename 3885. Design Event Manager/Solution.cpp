#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class EventManager {
public:
    EventManager(vector<vector<int>>& events)
    {
        id2priority.reserve(events.size());
        for (const vector<int>& event : events) {
            int eid = event[0], priority = event[1];
            id2priority[eid] = priority;
            pq.emplace(priority, -eid);
        }
    }

    void updatePriority(int eventId, int newPriority)
    {
        id2priority[eventId] = newPriority;
        pq.emplace(newPriority, -eventId);
    }

    int pollHighest()
    {
        while (!pq.empty()) {
            auto [priority, eid] = pq.top();
            pq.pop();
            eid = -eid;
            if (id2priority[eid] == priority) {
                id2priority.erase(eid);
                return eid;
            }
        }
        return -1;
    }

private:
    unordered_map<int, int> id2priority;
    priority_queue<pair<int, int>> pq;
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */
