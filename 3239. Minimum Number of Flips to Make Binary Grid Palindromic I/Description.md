# 3239. Minimum Number of Flips to Make Binary Grid Palindromic I

You are given an `m x n` binary matrix `grid`.

A row or column is considered **palindromic** if its values read the same forward and backward.

You can **flip** any number of cells in `grid` from `0` to `1`, or from `1` to `0`.

Return the **minimum** number of cells that need to be flipped to make **either** all rows **palindromic** or all columns **palindromic**.

**Example 1:**

![example 1](https://assets.leetcode.com/uploads/2024/07/07/screenshot-from-2024-07-08-00-20-10.png)

```()
Input: grid = [[1,0,0],[0,0,0],[0,0,1]]

Output: 2

Explanation: Flipping the highlighted cells makes all the rows palindromic.
```

**Example 2:**

![example 2](https://assets.leetcode.com/uploads/2024/07/07/screenshot-from-2024-07-08-00-31-23.png)

```()
Input: grid = [[0,1],[0,1],[0,0]]

Output: 1

Explanation: Flipping the highlighted cell makes all the columns palindromic.
```

**Example 3:**

```()
Input: grid = [[1],[0]]

Output: 0

Explanation:

All rows are already palindromic.
```

**Constraints:**

- `m == grid.length`
- `n == grid[i].length`
- `1 <= m * n <= 2 * 10^5`
- `0 <= grid[i][j] <= 1`
