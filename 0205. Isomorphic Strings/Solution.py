class Solution:
    def isIsomorphic_MK1(self, s: str, t: str) -> bool:
        for i in range((len(s))):
            if s.find(s[i]) != t.find(t[i]):
                return False
        return True

    def isIsomorphic_MK2(self, s: str, t: str) -> bool:
        hash_map = {}
        hash_set = set()
        for i in range(len(s)):
            if s[i] not in hash_map:
                if t[i] in hash_set:
                    return False
                else:
                    hash_map[s[i]] = t[i]
                    hash_set.add(t[i])
            elif hash_map[s[i]] != t[i]:
                return False
        return True

    def isIsomorphic_MK3(self, s: str, t: str) -> bool:
        return [*map(s.find, s)] == [*map(t.find, t)]

    def isIsomorphic_MK4(self, s: str, t: str) -> bool:
        return len(set(zip(s, t))) == len(set(s)) == len(set(t))
