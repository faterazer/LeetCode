class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Codec:
    def __init__(self) -> None:
        self.bitlen = 32
        self.mode = 'big'
        self.signed = True

    def serialize(self, root: TreeNode) -> str:
        """Encodes a tree to a single string.

        :type root: TreeNode
        :rtype: str
        """
        binarr = bytearray()

        def helper(root: TreeNode) -> None:
            if not root:
                binarr.append(0)
                return
            binarr.append(1)
            binarr.extend((root.val).to_bytes(
                self.bitlen, self.mode, signed=self.signed))
            helper(root.left)
            helper(root.right)

        helper(root)
        return binarr.decode(encoding='ISO-8859-1')

    def deserialize(self, data: str) -> TreeNode:
        """Decodes your encoded data to tree.

        :type data: str
        :rtype: TreeNode
        """
        binarr = data.encode(encoding='ISO-8859-1')
        idx = 0

        def helper() -> TreeNode:
            nonlocal idx
            if binarr[idx] == 0:
                idx += 1
                return None
            idx += 1
            root = TreeNode(int.from_bytes(
                binarr[idx:idx+self.bitlen], self.mode, signed=self.signed))
            idx += self.bitlen
            root.left = helper()
            root.right = helper()
            return root

        return helper()


# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))
