from typing import List


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def binaryTreePaths(self, root: TreeNode) -> List[str]:
        path_list = []
        if not root:
            return path_list
        self.allPaths(root, path_list, str(root.val))
        return path_list

    def allPaths(self, root: TreeNode, path_list: List[str], path: str) -> None:
        if not root.left and not root.right:
            path_list.append(path)
            return
        if root.left:
            self.allPaths(root.left, path_list, path + '->' + str(root.left.val))
        if root.right:
            self.allPaths(root.right, path_list, path + '->' + str(root.right.val))
