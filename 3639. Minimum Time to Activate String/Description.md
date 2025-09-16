# 3639. Minimum Time to Activate String

You are given a string `s` of length `n` and an integer array `order`, where `order` is a [permutation](A permutation is a rearrangement of all the elements of a set.) of the numbers in the range `[0, n - 1]`.

Starting from time `t = 0`, replace the character at index `order[t]` in `s` with `'*'` at each time step.

A [substring](A **substring** is a contiguous **non-empty** sequence of characters within a string.) is **valid** if it contains **at least** one `'*'`.

A string is **active** if the total number of **valid** substrings is greater than or equal to `k`.

Return the **minimum** time `t` at which the string `s` becomes **active**. If it is impossible, return -1.

**Example 1:**

| `t`  | `order[t]` | Modified `s` | Valid Substrings               | Count | Active (Count >= k) |
| ---- | ---------- | ------------ | ------------------------------ | ----- | ----------------------- |
| 0    | 1          | `"a*c"`      | `"*"`, `"a*"`, `"*c"`, `"a*c"` | 4     | Yes                     |

```()
Input: s = "abc", order = [1,0,2], k = 2

Output: 0

Explanation: The string s becomes active at t = 0. Thus, the answer is 0.
```

**Example 2:**

| `t`  | `order[t]` | Modified `s` | Valid Substrings                      | Count | Active (Count >= k) |
| ---- | ---------- | ------------ | ------------------------------------- | ----- | ---------------------------- |
| 0    | 0          | `"*at"`      | `"*"`, `"*a"`, `"*at"`                | 3     | No                           |
| 1    | 2          | `"*a*"`      | `"*"`, `"*a"`, `"*a*"`, `"a*"`, `"*"` | 5     | No                           |
| 2    | 1          | `"***"`      | All substrings (contain `'*'`)        | 6     | Yes                          |

```()
Input: s = "cat", order = [0,2,1], k = 6

Output: 2

Explanation: The string s becomes active at t = 2. Thus, the answer is 2.
```

**Example 3:**

```()
Input: s = "xy", order = [0,1], k = 4

Output: -1

Explanation: Even after all replacements, it is impossible to obtain k = 4 valid substrings. Thus, the answer is -1.
```

**Constraints:**

- `1 <= n == s.length <= 10^5`
- `order.length == n`
- `0 <= order[i] <= n - 1`
- `s` consists of lowercase English letters.
- `order` is a permutation of integers from 0 to `n - 1`.
- `1 <= k <= 10^9`
