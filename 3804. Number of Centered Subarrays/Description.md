# 3804. Number of Centered Subarrays

You are given an integer array `nums`.

A [subarry](A **subarray** is a contiguous **non-empty** sequence of elements within an array.) of `nums` is called **centered** if the sum of its elements is **equal to at least one** element within that **same subarray**.

Return the number of **centered subarrays** of `nums`.

**Example 1:**

```text
Input: nums = [-1,1,0]

Output: 5

Explanation:

- All single-element subarrays ([-1], [1], [0]) are centered.
- The subarray [1, 0] has a sum of 1, which is present in the subarray.
- The subarray [-1, 1, 0] has a sum of 0, which is present in the subarray.
- Thus, the answer is 5.
```

**Example 2:**

```text
Input: nums = [2,-3]

Output: 2

Explanation:

Only single-element subarrays ([2], [-3]) are centered.
```

**Constraints:**

- `1 <= nums.length <= 500`
- `-10^5 <= nums[i] <= 10^5`
