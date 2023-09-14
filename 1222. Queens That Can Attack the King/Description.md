# 1222. Queens That Can Attack the King

On a **0-indexed** `8 x 8` chessboard, there can be multiple black queens ad one white king.

You are given a 2D integer array `queens` where `queens[i] = [xQueen_i, yQueen_i]` represents the position of the `i-th` black queen on the chessboard. You are also given an integer array `king` of length `2` where `king = [xKing, yKing]` represents the position of the white king.

Return *the coordinates of the black queens that can directly attack the king*. You may return the answer in **any order**.

**Example 1:**

![example 1](https://assets.leetcode.com/uploads/2022/12/21/chess1.jpg)

```()
Input: queens = [[0,1],[1,0],[4,0],[0,4],[3,3],[2,4]], king = [0,0]
Output: [[0,1],[1,0],[3,3]]
Explanation: The diagram above shows the three queens that can directly attack the king and the three queens that cannot attack the king (i.e., marked with red dashes).
```

**Example 2:**

![example 2](https://assets.leetcode.com/uploads/2022/12/21/chess2.jpg)

```()
Input: queens = [[0,0],[1,1],[2,2],[3,4],[3,5],[4,4],[4,5]], king = [3,3]
Output: [[2,2],[3,4],[4,4]]
Explanation: The diagram above shows the three queens that can directly attack the king and the three queens that cannot attack the king (i.e., marked with red dashes).
```

**Constraints:**

- `1 <= queens.length < 64`
- `queens[i].length == king.length == 2`
- `0 <= xQueen_i, yQueen_i, xKing, yKing < 8`
- All the given positions are **unique**.
