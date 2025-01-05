from typing import List


class ATM:
    DENOMINATIONS = [20, 50, 100, 200, 500]
    N = len(DENOMINATIONS)

    def __init__(self) -> None:
        self.banknotes = [0] * ATM.N

    def deposit(self, banknotesCount: List[int]) -> None:
        for i, cnt in enumerate(banknotesCount):
            self.banknotes[i] += cnt

    def withdraw(self, amount: int) -> List[int]:
        ans = [0] * ATM.N
        for i in range(ATM.N - 1, -1, -1):
            ans[i] = min(self.banknotes[i], amount // ATM.DENOMINATIONS[i])
            amount -= ans[i] * ATM.DENOMINATIONS[i]
        if amount != 0:
            return [-1]
        for i, cnt in enumerate(ans):
            self.banknotes[i] -= cnt
        return ans


# Your ATM object will be instantiated and called as such:
# obj = ATM()
# obj.deposit(banknotesCount)
# param_2 = obj.withdraw(amount)
