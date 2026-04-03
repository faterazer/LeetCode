import heapq


class EventManager:

    def __init__(self, events: list[list[int]]):
        self.id2priority = {}
        self.pq = []
        for eventId, priority in events:
            self.id2priority[eventId] = priority
            self.pq.append((-priority, eventId))
        heapq.heapify(self.pq)

    def updatePriority(self, eventId: int, newPriority: int) -> None:
        self.id2priority[eventId] = newPriority
        heapq.heappush(self.pq, (-newPriority, eventId))

    def pollHighest(self) -> int:
        while self.pq:
            priority, eventId = heapq.heappop(self.pq)
            if self.id2priority.get(eventId, None) == -priority:
                self.id2priority.pop(eventId)
                return eventId
        return -1
