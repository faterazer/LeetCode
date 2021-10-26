class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.data_stk = []
        self.min_stk = []

    def push(self, x: int) -> None:
        self.data_stk.append(x)
        if not self.min_stk or x <= self.min_stk[-1]:
            self.min_stk.append(x)

    def pop(self) -> None:
        if self.min_stk[-1] == self.data_stk[-1]:
            self.min_stk.pop()
        self.data_stk.pop()

    def top(self) -> int:
        return self.data_stk[-1]

    def getMin(self) -> int:
        return self.min_stk[-1]

        # Your MinStack object will be instantiated and called as such:
        # obj = MinStack()
        # obj.push(x)
        # obj.pop()
        # param_3 = obj.top()
        # param_4 = obj.getMin()
