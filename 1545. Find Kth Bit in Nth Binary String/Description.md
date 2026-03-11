# 1545. Find Kth Bit in Nth Binary String

Given two positive integers `n` and `k`, the binary string `S_n` is formed as follows:

- $S_1 = \text{"0"}$
- $S_i = S_{i-1} + \texttt{"1"} + \text{reverse}(\text{invert}(S_{i-1}))$ for `i > 1`

Where `+` denotes the concatenation operation, `reverse(x)` returns the reversed string `x`, and `invert(x)` inverts all the bits in `x` (`0` changes to `1` and `1` changes to `0`).

For example, the first four strings in the above sequence are:

- $S_1 = \texttt{"0"}$
- $S_2 = \texttt{"011"}$
- $S_3 = \texttt{"0111001"}$
- $S_4 = \texttt{"011100110110001"}$

Return *the* `k-th` *bit in* `S_n`. It is guaranteed that `k` is valid for the given `n`.

**Example 1:**

```text
Input: n = 3, k = 1
Output: "0"
Explanation: S_3 is "0111001".
The 1st bit is "0".
```

**Example 2:**

```text
Input: n = 4, k = 11
Output: "1"
Explanation: S_4 is "011100110110001".
The 11-th bit is "1".
```

**Constraints:**

- `1 <= n <= 20`
- `1 <= k <= 2^{n - 1}`
