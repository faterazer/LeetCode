# 561. Array Partition I

Given an array of **2n** integers, your task is to group these integers into **n** pairs of integer, say $(a_1,b_1),(a_2,b_2),\ldots,(a_n,b_n)$ which makes sum of $min(a_i,b_i)$ for all `i` from `1` to `n` as large as possible.

**Example 1:**

```()
Input: [1,4,3,2]

Output: 4
Explanation: n is 2, and the maximum sum of pairs is 4 = min(1, 2) + min(3, 4).
```

**Note:**

1. **n** is a positive integer, which is in the range of [1, 10000].
2. All the integers in the array will be in the range of [-10000, 10000].
