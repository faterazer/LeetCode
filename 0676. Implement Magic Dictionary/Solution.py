import string
from typing import List


class Trie:
    def __init__(self) -> None:
        self.is_end = False
        self.children = {}


class MagicDictionary:
    def __init__(self):
        self.root = Trie()

    def buildDict(self, dictionary: List[str]) -> None:
        for word in dictionary:
            cur = self.root
            for c in word:
                if c not in cur.children:
                    cur.children[c] = Trie()
                cur = cur.children[c]
            cur.is_end = True

    def search(self, searchWord: str) -> bool:
        def dfs(root: Trie, word: str, idx: int, limit: int) -> bool:
            if idx == len(word):
                return root.is_end and limit == 0
            if word[idx] in root.children and dfs(root.children[word[idx]], word, idx + 1, limit):
                return True
            if limit > 0:
                for c in string.ascii_lowercase:
                    if c != word[idx] and c in root.children and dfs(root.children[c], word, idx + 1, limit - 1):
                        return True
            return False

        return dfs(self.root, searchWord, 0, 1)


# Your MagicDictionary object will be instantiated and called as such:
# obj = MagicDictionary()
# obj.buildDict(dictionary)
# param_2 = obj.search(searchWord)
