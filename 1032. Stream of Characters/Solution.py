from collections import defaultdict
from functools import reduce
from typing import List


class StreamChecker:
    def __init__(self, words: List[str]):
        Trie = lambda: defaultdict(Trie)
        self.trie = Trie()
        for word in words:
            reduce(dict.__getitem__, word[::-1], self.trie)["#"] = True
        self.char_stream = []

    def query(self, letter: str) -> bool:
        self.char_stream.append(letter)
        cur = self.trie
        for idx in range(len(self.char_stream) - 1, -1, -1):
            c = self.char_stream[idx]
            if c in cur:
                cur = cur[c]
                if cur["#"] == True:
                    return True
            else:
                break
        return False


# Your StreamChecker object will be instantiated and called as such:
# obj = StreamChecker(words)
# param_1 = obj.query(letter)
