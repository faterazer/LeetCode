class Solution:
    BUSINESS_LINE_TO_CATEGORY = {
        "electronics": 0,
        "grocery": 1,
        "pharmacy": 2,
        "restaurant": 3,
    }

    def validateCoupons(self, code: list[str], businessLine: list[str], isActive: list[bool]) -> list[str]:
        groups = [[] for _ in range(len(self.BUSINESS_LINE_TO_CATEGORY))]
        for identifier, category, active in zip(code, businessLine, isActive):
            gid = self.BUSINESS_LINE_TO_CATEGORY.get(category, -1)
            if gid >= 0 and identifier and all(c == "_" or c.isalnum() for c in identifier) and active:
                groups[gid].append(identifier)

        ans = []
        for g in groups:
            g.sort()
            ans.extend(g)
        return ans
