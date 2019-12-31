# 官方题解

## 方法一: 暴力法

对链表 `A` 中的每一个结点 $a_i$，遍历整个链表 `B` 并检查链表 `B` 中是否存在结点和 $a_i$ 相同。

### 复杂度分析

* 时间复杂度：$O(mn)$。
* 空间复杂度：$O(1)$。

## 方法二：哈希表法

遍历链表 `A` 并将每个结点的地址/引用存储在哈希表中。然后检查链表 `B` 中的每一个结点 $b_i$ 是否在哈希表中。若在，则 $b_i$ 为相交结点。

### 复杂度分析

* 时间复杂度：$O(m+n)$。
* 空间复杂度：$O(m)$ 或 $O(n)$。

## 方法三：双指针法

* 创建两个指针 $pA$ 和 $pB$，分别初始化为链表 `A` 和 `B` 的头结点。然后让它们向后逐结点遍历。
* 当 $pA$ 到达链表的尾部时，将它重定位到链表 `B` 的头结点 (你没看错，就是链表 `B`); 类似的，当 $pB$ 到达链表的尾部时，将它重定位到链表 `A` 的头结点。
* 若在某一时刻 $pA$ 和 $pB$ 相遇，则 $pA$/$pB$ 为相交结点。
* 想弄清楚为什么这样可行, 可以考虑以下两个链表: `A={1,3,5,7,9,11}` 和 `B={2,4,9,11}`，相交于结点 `9`。 由于 `B.length (=4) < A.length (=6)`，$pB$ 比 $pA$ 少经过 $2$ 个结点，会先到达尾部。将 $pB$ 重定向到 `A` 的头结点，`pA` 重定向到 `B` 的头结点后，$pB$ 要比 $pA$ 多走 `2` 个结点。因此，它们会同时到达交点。
* 如果两个链表存在相交，它们末尾的结点必然相同。因此当 $pA$/$pB$ 到达链表结尾时，记录下链表 `A/B` 对应的元素。若最后元素不相同，则两个链表不相交。

### 复杂度分析

* 时间复杂度：$O(m+n)$。
* 空间复杂度：$O(1)$。

***

# Solution

## Approach 1: Brute Force

For each node $a_i$ in list A, traverse the entire list B and check if any node in list B coincides with $a_i$.

### Complexity Analysis

* Time complexity: $O(mn)$.
* Space complexity: $O(1)$.

## Approach 2: Hash Table

Traverse list A and store the address/reference to each node in a hash set. Then check every node $b_i$ in list B; if $b_i$ appears in the hash set, then $b_i$ is the intersection node.  

### Complexity Analysis

* Time complexity: $O(m+n)$.
* Space complexity: $O(m)$ or $O(n)$.

## Approach 3: Two Pointers

* Maintain two pointers $pA$ and $pB$ initialized at the head of A and B, respectively. Then let them both traverse through the lists, one node at a time.
* When $pA$ reaches the end of a list, then redirect it to the head of B (yes, B, that's right.); similarly when $pB$ reaches the end of a list, redirect it the head of A.
* If any point $pA$ meets $pB$, then $pA$/$pB$ is the intersection node.
* To see why the above trick would work, consider the following two lists: A = {1,3,5,7,9,11} and B = {2,4,9,11}, which are intersected at node '9'. Since B.length (=4) < A.length (=6), $pB$ would reach the end of the merged list first, because $pB$ traverses exactly 2 nodes less than $pA$ does. By redirecting $pB$ to head A, and $pA$ to head B, we now ask $pB$ to travel exactly 2 more nodes than $pA$ would. So in the second iteration, they are guaranteed to reach the intersection node at the same time.
* If two lists have intersection, then their last nodes must be the same one. So when $pA$/$pB$ reaches the end of a list, record the last element of A/B respectively. If the two last elements are not the same one, then the two lists have no intersections.

### Complexity Analysis

* Time complexity: $O(m+n)$.
* Space complexity: $O(1)$.
