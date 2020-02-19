# 官方题解

## 方法：与下一个节点交换

从链表里删除一个节点 `node` 的最常见方法是修改*之前*节点的 `next` 指针，使其指向*之后*的节点。

![image-1](images/image2.png)

因为，我们无法访问我们想要删除的节点 *之前* 的节点，我们始终不能修改该节点的 `next` 指针。相反，我们必须将想要删除的节点的值替换为它后面节点中的值，然后删除它之后的节点。

![image-2](images/image3.png)
![image-3](images/image4.png)
![image-4](images/image5.png)

因为我们知道要删除的节点不是列表的末尾，所以我们可以保证这种方法是可行的。

**Java:**

```java
public void deleteNode(ListNode node) {
    node.val = node.next.val;
    node.next = node.next.next;
}
```

### 复杂度分析

时间和空间复杂度都是：$O(1)$。

***

# Solution

## Approach: Swap with Next Node [Accepted]

The usual way of deleting a node `node` from a linked list is to modify the `next` pointer of the node *before* it, to point to the node *after* it.

![image-1](images/image2.png)

Since we do not have access to the node *before* the one we want to delete, we cannot modify the `next` pointer of that node in any way. Instead, we have to replace the value of the node we want to delete with the value in the node after it, and then delete the node after it.

![image-2](images/image3.png)
![image-3](images/image4.png)
![image-4](images/image5.png)

Because we know that the node we want to delete is not the tail of the list, we can guarantee that this approach is possible.

**Java:**

```java
public void deleteNode(ListNode node) {
    node.val = node.next.val;
    node.next = node.next.next;
}
```

### Complexity Analysis

Time and space complexity are both $O(1)$.
