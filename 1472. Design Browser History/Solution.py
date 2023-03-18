class BrowserHistory:
    def __init__(self, homepage: str):
        self.history = [homepage]
        self.idx = 0
        self.length = 1

    def visit(self, url: str) -> None:
        if len(self.history) == self.idx + 1:
            self.history.append(url)
            self.idx += 1
        else:
            self.idx += 1
            self.history[self.idx] = url
        self.length = self.idx + 1

    def back(self, steps: int) -> str:
        if self.idx - steps >= 0:
            self.idx -= steps
        else:
            self.idx = 0
        return self.history[self.idx]

    def forward(self, steps: int) -> str:
        if self.idx + steps < self.length:
            self.idx += steps
        else:
            self.idx = self.length - 1
        return self.history[self.idx]


# Your BrowserHistory object will be instantiated and called as such:
# obj = BrowserHistory(homepage)
# obj.visit(url)
# param_2 = obj.back(steps)
# param_3 = obj.forward(steps)
