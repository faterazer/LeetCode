# 官方题解 (Solution)

## 方法一：暴力法

### 算法

在暴力法中，我们将会把所有可能爬的阶数进行组合，也就是 1 和 2。而在每一步中我们都会继续调用 $climbStairs$ 这个函数模拟爬 $1$ 阶和 $2$ 阶的情形，并返回两个函数的返回值之和。

$$
climbStairs(i, n) = climbStairs(i+1, n) + climbStairs(i+2, n)climbStairs(i, n) = climbStairs(i+1, n) + climbStairs(i+2, n)
$$

其中 $i$ 定义了当前阶数，而 $n$ 定义了目标阶数。

```java
public class Solution {
    public int climbStairs(int n) {
        int memo[] = new int[n + 1];
        return climb_Stairs(0, n, memo);
    }
    public int climb_Stairs(int i, int n, int memo[]) {
        if (i > n) {
            return 0;
        }
        if (i == n) {
            return 1;
        }
        if (memo[i] > 0) {
            return memo[i];
        }
        memo[i] = climb_Stairs(i + 1, n, memo) + climb_Stairs(i + 2, n, memo);
        return memo[i];
    }
}
```

### 复杂度分析

* 时间复杂度：$O(2^n)$，树形递归的大小为 $2^n$。
  在 n = 5 时的递归树将是这样的：
  ![recursion tree](images/image1.jpg)
* 空间复杂度：$O(n)$，递归树的深度可以达到 $n$。

## 方法二：记忆化递归

### 算法

在上一种方法中，我们计算每一步的结果时出现了冗余。另一种思路是，我们可以把每一步的结果存储在 $memo$ 数组之中，每当函数再次被调用，我们就直接从 $memo$ 数组返回结果。

在 $memo$ 数组的帮助下，我们得到了一个修复的递归树，其大小减少到 $n$。

```java
public class Solution {
    public int climbStairs(int n) {
        int memo[] = new int[n + 1];
        return climb_Stairs(0, n, memo);
    }
    public int climb_Stairs(int i, int n, int memo[]) {
        if (i > n) {
            return 0;
        }
        if (i == n) {
            return 1;
        }
        if (memo[i] > 0) {
            return memo[i];
        }
        memo[i] = climb_Stairs(i + 1, n, memo) + climb_Stairs(i + 2, n, memo);
        return memo[i];
    }
}
```

### 复杂度分析

* 时间复杂度：$O(n)$，树形递归的大小可以达到 $n$。
* 空间复杂度：$O(n)$，递归树的深度可以达到 $n$。

## 方法三：动态规划

### 算法

不难发现，这个问题可以被分解为一些包含最优子结构的子问题，即它的最优解可以从其子问题的最优解来有效地构建，我们可以使用动态规划来解决这一问题。

第 $i$ 阶可以由以下两种方法得到：

1. 在第 $(i-1)$ 阶后向上爬一阶。
2. 在第 $(i-2)$ 阶后向上爬两阶。

所以到达第 $i$ 阶的方法总数就是到第 $(i-1)$ 阶和第 $(i-2)$ 阶的方法数之和。

令 $dp[i]$ 表示能到达第 $i$ 阶的方法总数：

$$
dp[i] = dp[i-1] + dp[i-2]
$$

示例：

![动态规划](images/image2.gif)

```java
public class Solution {
    public int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        int[] dp = new int[n + 1];
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
}
```

### 复杂度分析

* 时间复杂度：$O(n)$，单循环到 $n$。
* 空间复杂度：$O(n)$，$dp$ 数组用了 $n$ 的空间。

## 方法四：斐波那契数

### 算法

在上述方法中，我们使用 $dp$ 数组，其中 $dp[i] = dp[i-1] + dp[i-2]$。可以很容易通过分析得出 $dp[i]$ 其实就是第 $i$ 个斐波那契数。

$$
Fib(n) = Fib(n-1) + Fib(n-2)
$$

现在我们必须找出以 $1$ 和 $2$ 作为第一项和第二项的斐波那契数列中的第 $n$ 个数，也就是说 $Fib(1) = 1$ 且 $Fib(2) = 2$。

```java
public class Solution {
    public int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        int first = 1;
        int second = 2;
        for (int i = 3; i <= n; i++) {
            int third = first + second;
            first = second;
            second = third;
        }
        return second;
    }
}
```

### 复杂度分析

* 时间复杂度：$O(n)$，计算第 $n$ 个斐波那契数，需要单循环到 $n$。
* 空间复杂度：$O(1)$，使用常量级空间。

## 方法五：Binets 方法

### 算法

这里有一种有趣的解法，它使用矩阵乘法来得到第 $n$ 个斐波那契数。矩阵形式如下：

$$
\begin{bmatrix}
F_{n+1} & F_N \\
F_n & F_{n-1}
\end{bmatrix}
=
\begin{bmatrix}
1 & 1 \\
1 & 0
\end{bmatrix}
$$

令 $Q = \begin{bmatrix} F_{n+1} & F_n \\ F_n & F_{n-1} \end{bmatrix}$。按照此方法，第 $n$ 个斐波那契数可以由 $Q^{n-1}[0, 0]$ 给出。

让我们试着证明一下。

我们可以使用数学归纳法来证明这一方法。易知，该矩阵给出了第 $3$ 项（基本情况）的正确结果。由于 $Q^2 = \begin{bmatrix}2 & 1 \\ 1 & 1\end{bmatrix}$。这证明基本情况是成立的。

假设此方法适用于查找第 $n$ 个斐波那契数，即 $F_n = Q^{n-1}[0,0]$，那么：

$$
Q^{n-1} = \begin{bmatrix}
F_n & F_{n-1} \\
F_{n-1} & F_{n-2}
\end{bmatrix}
$$

现在，我们需要证明在上述两个条件为真的情况下，该方法可以有效找出第 $(n+1)$ 个斐波那契数，即，$F_{n+1}=Q^{n}[0,0]$.

证明：

$$
\begin{aligned}
Q^n &= \begin{bmatrix}
F_n & F_{n-1} \\
F_{n-1} & F_{n-2}
\end{bmatrix}
\begin{bmatrix}
1 & 1 \\
1 & 0
\end{bmatrix} \\[2ex]
&= \begin{bmatrix}
F_n + F_{n-1} & F_n \\
F_{n-1} + F_{n-2} & F_{n-1}
\end{bmatrix} \\[2ex]
&= \begin{bmatrix}
F_{n+1} & F_n \\
F_n & F_{n-1}
\end{bmatrix}
\end{aligned}
$$

从而，$F_{n+1} = Q^n[0, 0]$，得证。

我们需要为我们的问题做的唯一改动就是将斐波那契数列的初始项修改为 2 和 1 来代替原来的 1 和 0。或者，另一种方法是使用相同的初始矩阵 $Q$ 并使用 $result=Q^n[0,0]$ 得出最后结果。发生这种情况的原因是我们必须使用原斐波那契数列的第 2 项和第 3 项作为初始项。

> 此处的代码（使用了二分求幂运算），以及后面的复杂度分析如果看不懂。可以看我关于二分求幂的文章：[二分求幂算法](https://zhuanlan.zhihu.com/p/67977216)

```java
 public class Solution {
    public int climbStairs(int n) {
        int[][] q = {{1, 1}, {1, 0}};
        int[][] res = pow(q, n);
        return res[0][0];
    }
    public int[][] pow(int[][] a, int n) {
        int[][] ret = {{1, 0}, {0, 1}};
        while (n > 0) {
            if ((n & 1) == 1) {
                ret = multiply(ret, a);
            }
            n >>= 1;
            a = multiply(a, a);
        }
        return ret;
    }
    public int[][] multiply(int[][] a, int[][] b) {
        int[][] c = new int[2][2];
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                c[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j];
            }
        }
        return c;
    }
}
```

### 复杂度分析

* 时间复杂度：$O(\log{n})$，遍历 $\log{n}$ 位。
* 空间复杂度：$O(1)$，使用常量级空间。

对时间复杂度的证明：

假设我们需要计算矩阵 $M$ 的 $n$ 次幂。假设，$n$ 是 2 的幂。因此，$n=2^i, i \in \Bbb{N}$，其中 $\Bbb{N}$ 表示自然数的集合（包括 0）。我们可以用树形结构进行表示：

![n 是 2 的幂](images/image3.png)

这意味着：$M^n = M^{n/2}$, $M^{n/2} = \cdots = \prod_1^n M^1$.

所以，要计算 $M^n$，我们先要计算 $M^{n/2}$ 并将其与自身相乘。而为了计算 $M^{n/2}$，我们需要对 $M^{n/4}$ 进行类似的操作，并依此类推。

显然，树的高度为 $\log_2{n}$。

让我们来估计一下 $M^n$ 计算所需要的时间。矩阵 $M$ 在幂运算过程中大小保持不变。因此，进行两矩阵幂乘的空间复杂度是 $O(1)$。我们需要执行 $\log_2{n}$ 次这样的乘法。所以，计算 $M^n$ 的时间复杂度为 $O(\log_2{n})$。

如果数字 $n$ 不是 2 的幂，我们可以使用其二进制表示将其转化为 2 的幂次项之和：

$$
n = \sum_{p\in P} 2^p, \text{ where } P \subset \Bbb{N}
$$

因此，我们可以使用以下方法获得最终结果：

$$
M^n = \prod_{p\in P} M^{2^p}
$$

这是我们在实现中使用的方法。 同样，时间复杂度仍为 $O(\log_2{n})$，因为乘法次数的限制为 $\log_2{n}$。

## 方法六：斐波那契公式

### 算法

我们可以使用这一公式来找出第 $n$ 个斐波那契数：

$$
F_n = 1/\sqrt{5} \left[ \left( \frac{1+\sqrt{5}}{2} \right)^n - \left( \frac{1-\sqrt{5}}{2} \right)^n \right]
$$

对于给定的问题，斐波那契序列将会被定义为 $F_0 = 1, F_1 = 1, F_2 = 2, F_{n+2} = F_{n+1} + F_n$。尝试解决这一递归公式的标准方法是设出 $F_n$​，其形式为 $F_n = a^n$。然后，自然有 $F_{n+1} = a^{n+1}$ 和 $F_{n+2} = a^{n+2}$，所以方程可以写作 $a^{n+2} = a^{n+1} + a^n$。如果我们对整个方程进行约分，可以得到 $a^2 = a + 1$ 或者写成二次方程形式 $a^2 - a - 1 = 0$。

对二次公式求解，我们得到：

$$
a = 1/\sqrt{5}\left( \frac{1\pm \sqrt{5}}{2} \right)
$$

一般解采用以下形式：

$$
F_n = A\left( \frac{1 + \sqrt{5}}{2} \right)^n + B\left( \frac{1- \sqrt{5}}{2} \right)^n
$$

$n=0$ 时，有 $A+B=1$。

$n=1$ 时，有 $A\left( \frac{1 + \sqrt{5}}{2} \right) + B\left( \frac{1- \sqrt{5}}{2} \right)=1$。

解上述等式，我们得到：

$$
A = \left( \frac{1+\sqrt{5}}{2\sqrt{5}} \right), B = -\left( \frac{1-\sqrt{5}}{2\sqrt{5}} \right)
$$

将 $A$ 和 $B$ 的这些值带入上述的一般解方程中，可以得到：

$$
F_n = 1/\sqrt{5}\left( \left( \frac{1+\sqrt{5}}{2} \right)^{n+1} - \left( \frac{1-\sqrt{5}}{2} \right)^{n+1} \right)
$$

```java
public class Solution {
    public int climbStairs(int n) {
        double sqrt5=Math.sqrt(5);
        double fibn=Math.pow((1+sqrt5)/2,n+1)-Math.pow((1-sqrt5)/2,n+1);
        return (int)(fibn/sqrt5);
    }
}
```

### 复杂度分析

* 时间复杂度：$O(\log n)$。$pow$ 将会用去 $\log n$ 的时间。
* 空间复杂度：$O(1)$，使用常量级空间。

***

## Approach 1: Brute Force

### Algorithm

In this brute force approach we take all possible step combinations i.e. 1 and 2, at every step. At every step we are calling the function $climbStairs$ for step $1$ and $2$, and return the sum of returned values of both functions.

$$
climbStairs(i, n) = climbStairs(i+1, n) + climbStairs(i+2, n)
$$

where $i$ defines the current step and $n$ defines the destination step.

```java
public class Solution {
    public int climbStairs(int n) {
        return climb_Stairs(0, n);
    }
    public int climb_Stairs(int i, int n) {
        if (i > n) {
            return 0;
        }
        if (i == n) {
            return 1;
        }
        return climb_Stairs(i + 1, n) + climb_Stairs(i + 2, n);
    }
}
```

### Complexity Analysis

* Time complexity: $O(2^n)$. Size of recursion tree will be $2^n$.
  Recursion tree for n = 5 would be like this:
  ![recursion tree](images/image1.jpg)
* Space complexity: $O(n)$. The depth of the recursion tree can go upto n.

## Approach 2: Recursion with Memoization

### Algorithm

In the previous approach we are redundantly calculating the result for every step. Instead, we can store the result at each step in $memo$ array and directly returning the result from the memo array whenever that function is called again.

In this way we are pruning recursion tree with the help of $memo$ array and reducing the size of recursion tree upto $n$.

```java
public class Solution {
    public int climbStairs(int n) {
        int memo[] = new int[n + 1];
        return climb_Stairs(0, n, memo);
    }
    public int climb_Stairs(int i, int n, int memo[]) {
        if (i > n) {
            return 0;
        }
        if (i == n) {
            return 1;
        }
        if (memo[i] > 0) {
            return memo[i];
        }
        memo[i] = climb_Stairs(i + 1, n, memo) + climb_Stairs(i + 2, n, memo);
        return memo[i];
    }
}
```

### Complexity Analysis

* Time complexity: $O(n)$. Size of recursion tree can go upto $n$.
* Space complexity: $O(n)$. The depth of recursion tree can go upto $n$.

## Approach 3: Dynamic Programming

### Algorithm

As we can see this problem can be broken into subproblems, and it contains the optimal substructure property i.e. its optimal solution can be constructed efficiently from optimal solutions of its subproblems, we can use dynamic programming to solve this problem.

One can reach $i^{th}$ step in one of the two ways:

1. Taking a single step from $(i-1)^{th}$ step.
2. Taking a step of 2 from $(i-2)^{th}$ step.

So, the total number of ways to reach $i^{th}$ is equal to sum of ways of reaching $(i-1)^{th}$ step and ways of reaching $(i-2)^{th}$ step.

Let $dp[i]$ denotes the number of ways to reach $i^{th}$ step:

$$
dp[i] = dp[i-1] + dp[i-2]
$$

Example:

![Dynamic Programming](images/image2.gif)

```java
public class Solution {
    public int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        int[] dp = new int[n + 1];
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
}
```

### Complexity Analysis

* Time complexity: $O(n)$. Single loop upto $n$.
* Space complexity: $O(n)$. $dp$ array of size $n$ is used.

## Approach 4: Fibonacci Number

### Algorithm

In the above approach we have used $dp$ array where $dp[i] = dp[i-1] + dp[i-2]$. It can be easily analysed that $dp[i]$ is nothing but $i^{th}$ fibonacci number.

$$
Fib(n) = Fib(n-1) + Fib(n-2)
$$

Now we just have to find $n^{th}$ number of the fibonacci series having $1$ and $2$ their first and second term respectively, i.e. $Fib(1) = 1$ and $Fib(2) = 2$.

```java
public class Solution {
    public int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        int first = 1;
        int second = 2;
        for (int i = 3; i <= n; i++) {
            int third = first + second;
            first = second;
            second = third;
        }
        return second;
    }
}
```

### Complexity Analysis

* Time complexity: $O(n)$. Single loop upto $n$ is required to calculate $n^{th}$ fibonacci number.
* Space complexity: $O(1)$. Constant space is used.

## Approach 5: Binets Method

### Algorithm

This is an interesting solution which uses matrix multiplication to obtain the $n^{th}$ Fibonacci Number. The matrix takes the following form:

$$
\begin{bmatrix}
F_{n+1} & F_N \\
F_n & F_{n-1}
\end{bmatrix}
=
\begin{bmatrix}
1 & 1 \\
1 & 0
\end{bmatrix}
$$

Let's say $Q = \begin{bmatrix} F_{n+1} & F_n \\ F_n & F_{n-1} \end{bmatrix}$. As per the method, the $n^{th}$ Fibonacci Number is given by $Q^{n-1}[0, 0]$.

Let's look at the proof of this method.

We can prove this method using Mathematical Induction. We know, this matrix gives the correct result for the $3^{rd}$ term (base case). Since $Q^2 = \begin{bmatrix}2 & 1 \\ 1 & 1\end{bmatrix}$. This proves that the base case holds.

Assume that this method holds for finding the $n^{th}$ Fibonacci Number, i.e. $F_n = Q^{n-1}[0,0]$, where

$$
Q^{n-1} = \begin{bmatrix}
F_n & F_{n-1} \\
F_{n-1} & F_{n-2}
\end{bmatrix}
$$

Now, we need to prove that with the above two conditions holding true, the method is valid for finding the $(n+1)^{th}$ Fibonacci Number, i.e. $F_{n+1}=Q^{n}[0,0]$.

Proof:

$$
\begin{aligned}
Q^n &= \begin{bmatrix}
F_n & F_{n-1} \\
F_{n-1} & F_{n-2}
\end{bmatrix}
\begin{bmatrix}
1 & 1 \\
1 & 0
\end{bmatrix} \\[2ex]
&= \begin{bmatrix}
F_n + F_{n-1} & F_n \\
F_{n-1} + F_{n-2} & F_{n-1}
\end{bmatrix} \\[2ex]
&= \begin{bmatrix}
F_{n+1} & F_n \\
F_n & F_{n-1}
\end{bmatrix}
\end{aligned}
$$

Thus, $F_{n+1} = Q^n[0, 0]$. This completes the proof of this method.

The only variation we need to do for our problem is that we need to modify the initial terms to 2 and 1 instead of 1 and 0 in the Fibonacci series. Or, another way is to use the same initial $Q$ matrix and use $result=Q^n[0,0]$ to get the final result. This happens because the initial terms we have to use are the 2nd and 3rd terms of the otherwise normal Fibonacci Series.

```java
 public class Solution {
    public int climbStairs(int n) {
        int[][] q = {{1, 1}, {1, 0}};
        int[][] res = pow(q, n);
        return res[0][0];
    }
    public int[][] pow(int[][] a, int n) {
        int[][] ret = {{1, 0}, {0, 1}};
        while (n > 0) {
            if ((n & 1) == 1) {
                ret = multiply(ret, a);
            }
            n >>= 1;
            a = multiply(a, a);
        }
        return ret;
    }
    public int[][] multiply(int[][] a, int[][] b) {
        int[][] c = new int[2][2];
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                c[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j];
            }
        }
        return c;
    }
}
```

### Complexity Analysis

* Time complexity: $O(\log{n})$. Traversing on $\log{n}$ bits.
* Space complexity: $O(1)$. Constant space is used.

Proof of Time Complexity:

Let's say there is a matrix $M$ to be raised to power $n$. Suppose, $n$ is the power of 2. Thus, $n = 2^i, i \in \Bbb{N}$, where $\Bbb{N}$ represents the set of natural numbers (including 0). We can represent in the form of a tree:

![n is the power of 2](images/image3.png)

Meaning that: $M^n = M^{n/2}$, $M^{n/2} = \cdots = \prod_1^n M^1$.

So, to calculate $M^n$ matrix, we should calculate $M^{n/2}$ matrix and multiply it by itself. To calculate $M^{n/2}$ we would have to do the same with $M^{n/4}$ and so on.

Obviously, the tree height is $\log_2{n}$.

Let's estimate $M^n$ calculation time. $M$ matrix is of the same size in any power. Therefore, we can perform the multiplication of two matrices in any power in $O(1)$. We should perform $\log_2{n}$ of such multiplications. So, $M^n$ calculation complexity is $O(\log_2{n})$.

In case, the number $n$ is not a power of two, we can break it in terms of powers of 2 using its binary representation:

$$
n = \sum_{p\in P} 2^p, \text{ where } P \subset \Bbb{N}
$$

Thus, we can obtain the final result using:

$$
M^n = \prod_{p\in P} M^{2^p}
$$

This is the method we've used in our implementation. Again, the complexity remains $O(\log_2{n})$ as we have limited the number of multiplications to $O(\log_2{n})$.

## Approach 6: Fibonacci Formula

### Algorithm

We can find $n^{th}$ fibonacci number using this formula:

$$
F_n = 1/\sqrt{5} \left[ \left( \frac{1+\sqrt{5}}{2} \right)^n - \left( \frac{1-\sqrt{5}}{2} \right)^n \right]
$$

For the given problem, the Fibonacci sequence is defined by $F_0 = 1, F_1 = 1, F_2 = 2, F_{n+2} = F_{n+1} + F_n$. A standard method of trying to solve such recursion formulas is assume $F_n$ of the form $F_n = a^n$. Then, of course, $F_{n+1} = a^{n+1}$ and $F_{n+2} = a^{n+2}$ so the equation becomes $a^{n+2} = a^{n+1} + a^n$. If we divide the entire equation by an we arrive at $a^2 = a + 1$ or the quadratic equation $a^2 - a - 1 = 0$.

Solving this by the quadratic formula, we get:

$$
a = 1/\sqrt{5}\left( \frac{1\pm \sqrt{5}}{2} \right)
$$

The general solution, thus takes the form:

$$
F_n = A\left( \frac{1 + \sqrt{5}}{2} \right)^n + B\left( \frac{1- \sqrt{5}}{2} \right)^n
$$

For $n=0$, we get $A+B=1$.

For $n=1$, we get $A\left( \frac{1 + \sqrt{5}}{2} \right) + B\left( \frac{1- \sqrt{5}}{2} \right)=1$

Solving the above equations, we get:

$$
A = \left( \frac{1+\sqrt{5}}{2\sqrt{5}} \right), B = -\left( \frac{1-\sqrt{5}}{2\sqrt{5}} \right)
$$

Putting these values of $A$ and $B$ in the above general solution equation, we get:

$$
F_n = 1/\sqrt{5}\left( \left( \frac{1+\sqrt{5}}{2} \right)^{n+1} - \left( \frac{1-\sqrt{5}}{2} \right)^{n+1} \right)
$$

```java
public class Solution {
    public int climbStairs(int n) {
        double sqrt5=Math.sqrt(5);
        double fibn=Math.pow((1+sqrt5)/2,n+1)-Math.pow((1-sqrt5)/2,n+1);
        return (int)(fibn/sqrt5);
    }
}
```

### Complexity Analysis

* Time complexity: $O(\log n)$. $pow$ method takes $\log n$ time.
* Space complexity: $O(1)$. Constant space is used.
