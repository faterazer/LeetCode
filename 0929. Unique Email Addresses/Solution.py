from typing import List


class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        seen = set()
        for email in emails:
            parts = email.split('@')
            local = parts[0].split('+')[0].replace('.', '')
            seen.add(local + '@' + parts[1])
        return len(seen)
