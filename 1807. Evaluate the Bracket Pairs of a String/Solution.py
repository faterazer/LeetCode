from typing import List


class Solution:
    def evaluate(self, s: str, knowledge: List[List[str]]) -> str:
        mapper = {k: v for k, v in knowledge}
        segments = s.split("(")
        res = [segments[0]]
        for seg in segments[1:]:
            key, remind = seg.split(")")
            res.append(mapper.get(key, "?"))
            res.append(remind)
        return "".join(res)
