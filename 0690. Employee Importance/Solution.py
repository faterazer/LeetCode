from typing import List


class Employee:
    def __init__(self, id: int, importance: int, subordinates: List[int]):
        self.id = id
        self.importance = importance
        self.subordinates = subordinates


class Solution:
    def getImportance(self, employees: List[Employee], id: int) -> int:
        employeeInHash = {e.id: e for e in employees}

        def dfs(id: int) -> int:
            total = employeeInHash[id].importance
            for subId in employeeInHash[id].subordinates:
                total += dfs(subId)
            return total

        return dfs(id)
