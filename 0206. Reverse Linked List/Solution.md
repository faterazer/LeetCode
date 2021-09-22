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
