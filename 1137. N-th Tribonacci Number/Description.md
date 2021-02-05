# 1137. N-th Tribonacci Number

The Tribonacci sequence $T_n$ is defined as follows:
$$
\mathrm{T}_{0}=0, \mathrm{~T}_{1}=1, \mathrm{~T}_{2}=1, \text { and } \mathrm{T}_{\mathrm{n}+3}=\mathrm{T}_{\mathrm{n}}+\mathrm{T}_{\mathrm{n}+1}+\mathrm{T}_{\mathrm{n}+2} \text { for } \mathrm{n}>=0
$$
Given `n`, return the value of $T_n$.

**Example 1:**

```()
Input: n = 4
Output: 4
Explanation:
T_3 = 0 + 1 + 1 = 2
T_4 = 1 + 1 + 2 = 4
```

**Example 2:**

```()
Input: n = 25
Output: 1389537
```

**Constraints:**

- $0 \leqslant \mathrm{n} \leqslant 37$
- The answer is guaranteed to fit within a 32-bit integer, i.e. `answer <= 2^31 - 1`.
