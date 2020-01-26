# 官方题解

## 方法 1：循环和位移动

### 算法

这个方法比较直接。我们遍历数字的 32 位。如果某一位是 $1$，将计数器加一。

我们使用 *位掩码* 来检查数字的第 $i^{th}$ 位。一开始，掩码 $m=1$ 因为 $1$ 的二进制表示是

$$
0000 0000 0000 0000 0000 0000 0000 0001
$$

显然，任何数字跟掩码 $1$ 进行逻辑与运算，都可以让我们获得这个数字的最低位。检查下一位时，我们将掩码左移一位。

$$
0000 0000 0000 0000 0000 0000 0000 0010
$$

并重复此过程。

**Java:**

```java
public int hammingWeight(int n) {
    int bits = 0;
    int mask = 1;
    for (int i = 0; i < 32; i++) {
        if ((n & mask) != 0) {
            bits++;
        }
        mask <<= 1;
    }
    return bits;
}
```

### 复杂度分析

* 时间复杂度：$O(1)$。运行时间依赖于数字 $n$ 的位数。由于这题中 $n$ 是一个 32 位数，所以运行时间是 $O(1)$ 的。
* 空间复杂度：$O(1)$。没有使用额外空间。

## 方法 2：位操作的小技巧

### 算法

我们可以把前面的算法进行优化。我们不再检查数字的每一个位，而是不断把数字最后一个 $1$ 反转，并把答案加一。当数字变成 $0$ 的时候，我们就知道它没有 $1$ 的位了，此时返回答案。

这里关键的想法是对于任意数字 $n$，将 $n$ 和 $n-1$ 做与运算，会把最后一个 $1$ 的位变成 $0$。为什么？考虑 $n$ 和 $n-1$ 的二进制表示。

![图片 1. 将 nnn 和 n−1n-1n−1 做与运算会将最低位的 111 变成 000](images/image1.png)

在二进制表示中，数字 $n$ 中最低位的 $1$ 总是对应 $n-1$ 中的 $0$。因此，将 $n$ 和 $n-1$ 与运算总是能把 $n$ 中最低位的 $1$ 变成 $0$ ，并保持其他位不变。

使用这个小技巧，代码变得非常简单。

**Java:**

```java
public int hammingWeight(int n) {
    int sum = 0;
    while (n != 0) {
        sum++;
        n &= (n - 1);
    }
    return sum;
}
```

### 复杂度分析

* 时间复杂度：$O(1)$。运行时间与 $n$ 中位为 $1$ 的有关。在最坏情况下， $n$ 中所有位都是 $1$ 。对于 32 位整数，运行时间是 $O(1)$ 的。
* 空间复杂度：$O(1)$。没有使用额外空间。

***

# Solution

## Approach #1 (Loop and Flip) [Accepted]

### Algorithm

The solution is straight-forward. We check each of the $32$ bits of the number. If the bit is $1$, we add one to the number of $1$-bits.

We can check the $i^{th}$ bit of a number using a *bit mask*. We start with a mask $m=1$, because the binary representation of $1$ is,

$$
0000 0000 0000 0000 0000 0000 0000 0001
$$

Clearly, a logical AND between any number and the mask $1$ gives us the least significant bit of this number. To check the next bit, we shift the mask to the left by one.

$$
0000 0000 0000 0000 0000 0000 0000 0010
$$

And so on.

**Java:**

```java
public int hammingWeight(int n) {
    int bits = 0;
    int mask = 1;
    for (int i = 0; i < 32; i++) {
        if ((n & mask) != 0) {
            bits++;
        }
        mask <<= 1;
    }
    return bits;
}
```

### Complexity Analysis

The run time depends on the number of bits in $n$. Because $n$ in this piece of code is a 32-bit integer, the time complexity is $O(1)$.

The space complexity is $O(1)$, since no additional space is allocated.

## Approach #2 (Bit Manipulation Trick) [Accepted]

### Algorithm

We can make the previous algorithm simpler and a little faster. Instead of checking every bit of the number, we repeatedly flip the least-significant 1-bit of the number to $0$, and add $1$ to the sum. As soon as the number becomes $0$, we know that it does not have any more 1-bits, and we return the sum.

The key idea here is to realize that for any number $n$, doing a bit-wise AND of $n$ and $n-1$ flips the least-significant 1-bit in $n$ to $0$. Why? Consider the binary representations of $n$ and $n-1$.

![Figure 1. AND-ing nnn and n−1n-1n−1 flips the least-significant 111-bit to 0.](images/image1.png)

In the binary representation, the least significant 1-bit in $n$ always corresponds to a 0-bit in $n-1$. Therefore, anding the two numbers $n$ and $n-1$ always flips the least significant 1-bit in $n$ to 0, and keeps all other bits the same.

Using this trick, the code becomes very simple.

**Java:**

```java
public int hammingWeight(int n) {
    int sum = 0;
    while (n != 0) {
        sum++;
        n &= (n - 1);
    }
    return sum;
}
```

### Complexity Analysis

The run time depends on the number of 1-bits in $n$. In the worst case, all bits in $n$ are 1-bits. In case of a 32-bit integer, the run time is $O(1)$.

The space complexity is $O(1)$, since no additional space is allocated.
