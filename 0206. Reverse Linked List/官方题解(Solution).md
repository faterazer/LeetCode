# 官方题解

## 方法一：迭代

假设存在链表 `1 → 2 → 3 → Ø`，我们想要把它改成 `Ø ← 1 ← 2 ← 3`。

在遍历列表时，将当前节点的 `next` 指针改为指向前一个元素。由于节点没有引用其上一个节点，因此必须事先存储其前一个元素。在更改引用之前，还需要另一个指针来存储下一个节点。不要忘记在最后返回新的头引用！

```java
public ListNode reverseList(ListNode head) {
    ListNode prev = null;
    ListNode curr = head;
    while (curr != null) {
        ListNode nextTemp = curr.next;
        curr.next = prev;
        prev = curr;
        curr = nextTemp;
    }
    return prev;
}
```

### 复杂度分析

* 时间复杂度：$O(n)$，假设 $n$ 是列表的长度，时间复杂度是 $O(n)$。
* 空间复杂度：$O(1)$。

## 方法二：递归

递归版本稍微复杂一些，其关键在于反向工作。假设列表的其余部分已经被反转，现在我该如何反转它前面的部分？

假设列表为：

$$
n_1 \rightarrow \ldots \rightarrow n_k \rightarrow n_{k+1} \rightarrow \ldots \rightarrow n_m \rightarrow \emptyset
$$

若从节点 $n_{k+1}$​ 到 $n_{m}$​ 已经被反转，而我们正处于 $n_{k}$​。

$$
n_1 \rightarrow \ldots \rightarrow n_k \rightarrow n_{k+1} \leftarrow \ldots \leftarrow n_m
$$

我们希望 $n_{k+1}$​ 的下一个节点指向 $n_{k}$​。

所以，$n_{k}​.next.next = n_{k}$​。

要小心的是 $n_{1}$​ 的下一个必须指向 $\emptyset$。如果你忽略了这一点，你的链表中可能会产生循环。如果使用大小为 2 的链表测试代码，则可能会捕获此错误。

```java
public ListNode reverseList(ListNode head) {
    if (head == null || head.next == null) return head;
    ListNode p = reverseList(head.next);
    head.next.next = head;
    head.next = null;
    return p;
}
```

### 复杂度分析

* 时间复杂度：$O(n)$，假设 $n$ 是列表的长度，那么时间复杂度为 $O(n)$。
* 空间复杂度：$O(n)$，由于使用递归，将会使用隐式栈空间。递归深度可能会达到 $n$ 层。

***

# Solution

## Approach #1 (Iterative) [Accepted]

Assume that we have linked list `1 -> 2 -> 3 -> null`, we would like to change it to `null <- 1 <- 2 <- 3`.

While you are traversing the list, change the current node's next pointer to point to its previous element. Since a node does not have reference to its previous node, you must store its previous element beforehand. You also need another pointer to store the next node before changing the reference. Do not forget to return the new head reference at the end!

```java
public ListNode reverseList(ListNode head) {
    ListNode prev = null;
    ListNode curr = head;
    while (curr != null) {
        ListNode nextTemp = curr.next;
        curr.next = prev;
        prev = curr;
        curr = nextTemp;
    }
    return prev;
}
```

### Complexity analysis

* Time complexity: $O(n)$. Assume that $n$ is the list's length, the time complexity is $O(n)$.
* Space complexity: $O(1)$.

## Approach #2 (Recursive) [Accepted]

The recursive version is slightly trickier and the key is to work backwards. Assume that the rest of the list had already been reversed, now how do I reverse the front part? Let's assume the list is: $n_1 \rightarrow \ldots \rightarrow n_{k-1} \rightarrow n_k \rightarrow n_{k+1} \rightarrow \ldots \rightarrow n_m \rightarrow \emptyset$.

Assume from node $n_{k+1}$ to $n_m$ had been reversed and you are at node $n_k$.

$$
n_1 \rightarrow \ldots \rightarrow n_k \rightarrow n_{k+1} \leftarrow \ldots \leftarrow n_m
$$

We want $n_{k+1}$'s next node to point to $n_k$.

So, $n_k.next.next = n_k$.

Be very carefully that $n_1$'s next must point to $\emptyset$. If you forget about this, your linked list has a cycle in it. This bug could be caught if you test your code with a linked list of size 2.

```java
public ListNode reverseList(ListNode head) {
    if (head == null || head.next == null) return head;
    ListNode p = reverseList(head.next);
    head.next.next = head;
    head.next = null;
    return p;
}
```

### Complexity analysis

* Time complexity: $O(n)$. Assume that $n$ is the list's length, the time complexity is $O(n)$.
* Space complexity: $O(n)$. The extra space comes from implicit stack space due to recursion. The recursion could go up to $n$ levels deep.
