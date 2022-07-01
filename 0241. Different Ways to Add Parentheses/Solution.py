import operator
from typing import List


class Solution:
    def diffWaysToCompute(self, expression: str) -> List[int]:
        memo = {}
        ch2op = {
            '+': operator.add,
            '-': operator.sub,
            '*': operator.mul
        }

        def compute(expression: str) -> List[int]:
            if expression in memo:
                return memo[expression]
            res = []
            for i, c in enumerate(expression):
                if c.isdigit():
                    continue
                left = compute(expression[:i])
                right = compute(expression[i+1:])
                op = ch2op[c]
                res.extend([op(a, b) for a in left for b in right])
            if not res:
                res = [int(expression)]
            memo[expression] = res
            return res

        return compute(expression)
