class LinkNode:
    def __init__(self, val: int) -> None:
        self.val = val
        self.next = None


class MyLinkedList:

    def __init__(self):
        self.head = LinkNode(0)
        self.tail = self.head

    def get(self, index: int) -> int:
        if index < 0 or index >= self.head.val:
            return -1

        p = self.head.next
        for _ in range(index):
            p = p.next
        return p.val

    def addAtHead(self, val: int) -> None:
        p = LinkNode(val)
        p.next = self.head.next
        self.head.next = p
        self.head.val += 1
        if self.tail == self.head:
            self.tail = self.head.next

    def addAtTail(self, val: int) -> None:
        p = LinkNode(val)
        self.tail.next = p
        self.tail = p
        self.head.val += 1

    def addAtIndex(self, index: int, val: int) -> None:
        if index > self.head.val:
            return

        if index < 0:
            self.addAtHead(val)
        elif index == self.head.val:
            self.addAtTail(val)
        else:
            pre = self.head
            for _ in range(index):
                pre = pre.next
            p = LinkNode(val)
            p.next = pre.next
            pre.next = p
            self.head.val += 1

    def deleteAtIndex(self, index: int) -> None:
        if index < 0 or index >= self.head.val:
            return
        pre = self.head
        for _ in range(index):
            pre = pre.next
        p = pre.next
        pre.next = p.next
        if p == self.tail:
            self.tail = pre
        self.head.val -= 1


# Your MyLinkedList object will be instantiated and called as such:
# obj = MyLinkedList()
# param_1 = obj.get(index)
# obj.addAtHead(val)
# obj.addAtTail(val)
# obj.addAtIndex(index,val)
# obj.deleteAtIndex(index)
