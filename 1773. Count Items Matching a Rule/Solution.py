from typing import List


class Solution:
    def countMatches(self, items: List[List[str]], ruleKey: str, ruleValue: str) -> int:
        key2idx = {'type': 0, 'color': 1, 'name': 2}
        return sum(item[key2idx[ruleKey]] == ruleValue for item in items)
