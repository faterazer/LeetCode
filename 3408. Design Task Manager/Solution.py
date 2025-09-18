import heapq


class TaskManager:

    def __init__(self, tasks: list[list[int]]):
        self.task_map = {task_id: (user_id, priority) for user_id, task_id, priority in tasks}
        self.task_heap = [(-priority, -task_id, user_id) for user_id, task_id, priority in tasks]
        heapq.heapify(self.task_heap)

    def add(self, userId: int, taskId: int, priority: int) -> None:
        self.task_map[taskId] = (userId, priority)
        heapq.heappush(self.task_heap, (-priority, -taskId, userId))

    def edit(self, taskId: int, newPriority: int) -> None:
        self.add(self.task_map[taskId][0], taskId, newPriority)

    def rmv(self, taskId: int) -> None:
        self.task_map.pop(taskId, None)

    def execTop(self) -> int:
        while self.task_heap:
            priority, task_id, user_id = heapq.heappop(self.task_heap)
            if (task_id := -task_id) in self.task_map and self.task_map[task_id] == (user_id, -priority):
                self.rmv(task_id)
                return user_id
        return -1


# Your TaskManager object will be instantiated and called as such:
# obj = TaskManager(tasks)
# obj.add(userId,taskId,priority)
# obj.edit(taskId,newPriority)
# obj.rmv(taskId)
# param_4 = obj.execTop()
