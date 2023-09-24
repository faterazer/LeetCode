class DLinkedNode:
    def __init__(self, k: int = 0, v: int = 0) -> None:
        self.key = k
        self.val = v
        self.pre: DLinkedNode = None
        self.next: DLinkedNode = None


class LRUCache:
    def __init__(self, capacity: int):
        self.table = {}
        self.head, self.tail = DLinkedNode(), DLinkedNode()
        self.head.next, self.tail.pre = self.tail, self.head
        self.capacity = capacity

    def get(self, key: int) -> int:
        if key not in self.table:
            return -1
        p = self.table[key]
        self._detach(p)
        self._pushFront(p)
        return p.val

    def put(self, key: int, value: int) -> None:
        if key in self.table:
            node = self.table[key]
            node.val = value
            self._detach(node)
            self._pushFront(node)
            return

        if len(self.table) == self.capacity:
            self._popBack()
        node = DLinkedNode(key, value)
        self._pushFront(node)
        self.table[key] = node

    def _detach(self, node: DLinkedNode) -> None:
        node.pre.next = node.next
        node.next.pre = node.pre

    def _pushFront(self, node: DLinkedNode) -> None:
        node.next = self.head.next
        self.head.next = node
        node.next.pre = node
        node.pre = self.head

    def _popBack(self) -> None:
        node = self.tail.pre
        node.pre.next = self.tail
        self.tail.pre = node.pre
        self.table.pop(node.key)


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
