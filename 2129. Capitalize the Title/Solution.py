class Solution:
    def capitalizeTitle(self, title: str) -> str:
        return " ".join(s.title() if len(s) > 2 else s.lower() for s in title.split())
