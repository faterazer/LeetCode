from typing import List


class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        stack = [] 
        mp = {}
        for n in nums2:
            while stack and stack[-1] < n:
                mp[stack.pop()] = n
            stack.append(n)
        return [mp.get(n, -1) for n in nums1]
