from typing import List


class Solution:
    def canFormArray(self, arr: List[int], pieces: List[List[int]]) -> bool:
        n2p = {p[0]: p for p in pieces}
        i = 0
        while i < len(arr):
            if arr[i] not in n2p:
                return False
            p = n2p[arr[i]]
            if arr[i:i + len(p)] != p:
                return False
            i += len(p)
        return True
