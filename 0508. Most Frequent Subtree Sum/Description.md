# 508. Most Frequent Subtree Sum

Given the `root` of a binary tree, return the most frequent **subtree sum**. If there is a tie, return all the values with the highest frequency in any order.

The **subtree sum** of a node is defined as the sum of all the node values formed by the subtree rooted at that node (including the node itself).

**Example 1:**

![example](https://assets.leetcode.com/uploads/2021/04/24/freq1-tree.jpg)

```()
Input: root = [5,2,-3]
Output: [2,-3,4]
```

**Example 2:**

![example 2](https://assets.leetcode.com/uploads/2021/04/24/freq2-tree.jpg)

```()
Input: root = [5,2,-5]
Output: [2]
```

**Constraints:**

- The number of nodes in the tree is in the range `[1, 10^4]`.
- `-10^5 <= Node.val <= 10^5`
