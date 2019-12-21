# 141. 环形链表

给定一个链表，判断链表中是否有环。

为了表示给定链表中的环，我们使用整数 `pos` 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 `pos` 是 `-1`，则在该链表中没有环。

**示例 1：**

```()
输入：head = [3,2,0,-4], pos = 1
输出：true
```

**解释:** 链表中有一个环，其尾部连接到第二个节点。

![image 1](images/image1.png)

**示例 2：**

```()
输入：head = [1,2], pos = 0
输出：true
```

**解释:** 链表中有一个环，其尾部连接到第一个节点。

![image 2](images/image2.png)

**示例 3：**

```()
输入：head = [1], pos = -1
输出：false
```

**解释:** 链表中没有环。

**进阶：**

你能用 $O(1)$（即，常量）内存解决此问题吗？

***

# 141. Linked List Cycle

Given a linked list, determine if it has a cycle in it.

To represent a cycle in the given linked list, we use an integer `pos` which represents the position (0-indexed) in the linked list where tail connects to. if `pos` is `-1`, then there is no cycle in the linked list.

**Example 1:**

```()
Input: head = [3,2,0,-4], pos = 1
Output: true
```

**Explanation:** There is a cycle in the linked list, where tail connects to the second node.

![image 1](images/image1.png)

**Example 2:**

```()
Input: head = [1,2], pos = 0
Output: true
```

**Explanation:** There is a cycle in the linked list, where tail connects to the first node.

![image 2](images/image2.png)

**Example 3:**

```()
Input: head = [1], pos = -1
Output: false
```

**Explanation:** There is no cycle in the linked list.

![image 3](images/image3.png)

**Follow up:**

Can you solve it using $O(1)$ (i.e. constant) memory?
