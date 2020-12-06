import collections
from typing import List


class Solution:
    def subdomainVisits(self, cpdomains: List[str]) -> List[str]:
        counter = collections.Counter()
        for cpdomain in cpdomains:
            n, domain = cpdomain.split(' ')
            n = int(n)
            frag = domain.split('.')
            for i in range(len(frag)):
                counter['.'.join(frag[i:])] += n
        return ['{} {}'.format(cnt, dom) for dom, cnt in counter.items()]
