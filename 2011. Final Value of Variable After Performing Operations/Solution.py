class Solution:
    def finalValueAfterOperations(self, operations: list[str]) -> int:
        return sum(1 if op[1] == "+" else -1 for op in operations)
