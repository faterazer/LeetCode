#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class TaskManager {
public:
    TaskManager(vector<vector<int>>& tasks)
    {
        for (const vector<int>& task : tasks)
            add(task[0], task[1], task[2]);
    }

    void add(int userId, int taskId, int priority)
    {
        task_pq.emplace(priority, taskId, userId);
        task_map[taskId] = { userId, priority };
    }

    void edit(int taskId, int newPriority)
    {
        add(task_map[taskId].first, taskId, newPriority);
    }

    void rmv(int taskId)
    {
        task_map.erase(taskId);
    }

    int execTop()
    {
        while (!task_pq.empty()) {
            auto [priority, taskId, userId] = task_pq.top();
            task_pq.pop();
            if (task_map.contains(taskId) && task_map[taskId].second == priority) {
                rmv(taskId);
                return userId;
            }
        }
        return -1;
    }

private:
    priority_queue<tuple<int, int, int>> task_pq; // (priority, taskId, userId)
    unordered_map<int, pair<int, int>> task_map; // taskId -> (userId, priority)
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */
