# 1437. Check If All 1's Are at Least Length K Places Away

Given an array `nums` of 0s and 1s and an integer `k`, return `True` if all 1's are at least `k` places away from each other, otherwise return `False`.

**Example 1:**

![example](https://assets.leetcode.com/uploads/2020/04/15/sample_1_1791.png)

```()
Input: nums = [1,0,0,0,1,0,0,1], k = 2
Output: true
Explanation: Each of the 1s are at least 2 places away from each other.
```

**Example 2:**
![example](https://assets.leetcode.com/uploads/2020/04/15/sample_2_1791.png)

```()
Input: nums = [1,0,0,1,0,1], k = 2
Output: false
Explanation: The second 1 and third 1 are only one apart from each other.
```

**Example 3:**

```()
Input: nums = [1,1,1,1,1], k = 0
Output: true
```

**Example 4:**

```()
Input: nums = [0,1,0,1], k = 1
Output: true
```

**Constraints:**

- $1 \leq nums.length \leq 10^5$
- $0 \leq k \leq nums.length$
- `nums[i]` is `0` or `1`
