# 移除链表元素

## 方法：哨兵节点

如果删除的节点是中间的节点，则问题似乎非常简单：

* 选择要删除节点的前一个结点 `prev`。
* 将 `prev` 的 `next` 设置为要删除结点的 `next`。

![image-1](images/image1.png)

当要删除的一个或多个节点位于链表的头部时，事情会变得复杂。

![image-2](images/image2.png)

可以通过哨兵节点去解决它，哨兵节点广泛应用于树和链表中，如伪头、伪尾、标记等，它们是纯功能的，通常不保存任何数据，其主要目的是使链表标准化，如使链表永不为空、永不无头、简化插入和删除。

![image3](images/image3.png)

在这里哨兵节点将被用于伪头。

### 算法

* 初始化哨兵节点为 `ListNode(0)` 且设置 `sentinel.next=head`。
* 初始化两个指针 `curr` 和 `prev` 指向当前节点和前继节点。
* 当 `curr != nullptr`：
  * 比较当前节点和要删除的节点：
    * 若当前节点就是要删除的节点：则 `prev.next = curr.next`。
    * 否则设 `prve = curr`。
  * 遍历下一个元素：`curr = curr.next`。
* 返回 `sentinel.next`。

Python:

```python
class Solution:
    def removeElements(self, head: ListNode, val: int) -> ListNode:
        sentinel = ListNode(0)
        sentinel.next = head

        prev, curr = sentinel, head
        while curr:
            if curr.val == val:
                prev.next = curr.next
            else:
                prev = curr
            curr = curr.next

        return sentinel.next
```

Java:

```java
class Solution {
  public ListNode removeElements(ListNode head, int val) {
    ListNode sentinel = new ListNode(0);
    sentinel.next = head;

    ListNode prev = sentinel, curr = head;
    while (curr != null) {
      if (curr.val == val) prev.next = curr.next;
      else prev = curr;
      curr = curr.next;
    }
    return sentinel.next;
  }
}
```

C++:

```cpp
class Solution {
  public:
  ListNode* removeElements(ListNode* head, int val) {
    ListNode* sentinel = new ListNode(0);
    sentinel->next = head;

    ListNode *prev = sentinel, *curr = head, *toDelete = nullptr;
    while (curr != nullptr) {
      if (curr->val == val) {
        prev->next = curr->next;
        toDelete = curr;
      } else prev = curr;

      curr = curr->next;

      if (toDelete != nullptr) {
        delete toDelete;
        toDelete = nullptr;
      }
    }

    ListNode *ret = sentinel->next;
    delete sentinel;
    return ret;
  }
};
```

### 复杂度分析

* 时间复杂度：$O(N)$，只遍历了一次。
* 空间复杂度：$O(1)$。
