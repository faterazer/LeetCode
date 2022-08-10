import re
from operator import sub


class Solution:
    def solveEquation(self, equation: str) -> str:
        sub_equations = re.sub(r'\bx', '1x', equation).split('=')
        factors, vals = [], []
        for eq in sub_equations:
            factors.append(sum(int(token) for token in re.findall(r'([-+]?\d+)x', eq)))
            vals.append(sum(int(token) for token in re.findall(r'([-+]?\d+)\b', eq)))

        factor, val = sub(*factors), -sub(*vals)
        if factor == 0 and val == 0:
            return 'Infinite solutions'
        elif factor == 0:
            return 'No solution'
        else:
            return 'x=' + str(val // factor)
