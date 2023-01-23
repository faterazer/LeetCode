from typing import List


class Solution:
    def calculateTax(self, brackets: List[List[int]], income: int) -> float:
        tax = prev = 0.0
        for upper, percent in brackets:
            tax += (min(income, upper) - prev) * percent / 100
            prev = upper
            if income <= upper:
                break
        return tax
