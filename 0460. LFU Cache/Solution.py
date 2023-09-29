from collections import defaultdict


class DLinkedNode:
    __slots__ = "key", "value", "freq", "prev", "next"

    def __init__(self, key: int = 0, value: int = 0) -> None:
        self.key = key
        self.value = value
        self.freq = 1


class LFUCache:
    def __init__(self, capacity: int):
        self.capacity = capacity
        self.key2node = {}

        def newDLinkedList() -> DLinkedNode:
            head = DLinkedNode()
            head.prev = head
            head.next = head
            return head

        self.freq2list = defaultdict(newDLinkedList)
        self.min_freq = 1

    def get(self, key: int) -> int:
        if key not in self.key2node:
            return -1
        return self.get_node(key).value

    def put(self, key: int, value: int) -> None:
        if key in self.key2node:
            node = self.get_node(key)
            node.value = value
        else:
            if len(self.key2node) == self.capacity:
                back_node = self.popBack(self.freq2list[self.min_freq])
                self.key2node.pop(back_node.key)
                if self.freq2list[self.min_freq].next == self.freq2list[self.min_freq]:
                    self.freq2list.pop(self.min_freq)
            node = DLinkedNode(key, value)
            self.key2node[key] = node
            self.pushFront(self.freq2list[1], node)
            self.min_freq = 1

    def get_node(self, key: int) -> DLinkedNode:
        node = self.key2node[key]
        node.prev.next = node.next
        node.next.prev = node.prev

        head = self.freq2list[node.freq]
        if head.next == head:
            self.freq2list.pop(node.freq)
            if self.min_freq == node.freq:
                self.min_freq += 1
        node.freq += 1
        self.pushFront(self.freq2list[node.freq], node)
        return node

    def pushFront(self, head: DLinkedNode, node: DLinkedNode) -> None:
        node.next = head.next
        node.prev = head
        head.next = node
        node.next.prev = node

    def popBack(self, head: DLinkedNode) -> DLinkedNode:
        node = head.prev
        node.prev.next = head
        head.prev = node.prev
        return node


# Your LFUCache object will be instantiated and called as such:
# obj = LFUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
