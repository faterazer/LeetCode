# Solution

## Approach : Pop and Push Digits & Check before Overflow

### Intuition

We can build up the reverse integer one digit at a time. While doing so, we can check beforehand whether or not appending another digit would cause overflow.

### Algorithm

Reversing an integer can be done similarly to reversing a string.

We want to repeatedly "pop" the last digit off of $x$ and "push" it to the back of the $\text{rev}$. In the end, $\text{rev}$ will be the reverse of the $x$.

To "pop" and "push" digits without the help of some auxiliary stack/array, we can use math.

```c
//pop operation:
pop = x % 10;
x /= 10;

//push operation:
temp = rev * 10 + pop;
rev = temp;
```

However, this approach is dangerous, because the statement $\text{temp} = \text{rev} \cdot 10 + \text{pop}$ can cause overflow.

Luckily, it is easy to check beforehand whether or this statement would cause an overflow.

To explain, lets assume that $\text{rev}$ is positive.

1. If $temp = \text{rev} \cdot 10 + \text{pop}$ causes overflow, then it must be that $\text{rev} \geq \frac{INTMAX}{10}$
2. If $\text{rev} > \frac{INTMAX}{10}$, then $temp = \text{rev} \cdot 10 + \text{pop}$ is guaranteed to overflow.
3. If $\text{rev} == \frac{INTMAX}{10}$, then $temp = \text{rev} \cdot 10 + \text{pop}$ will overflow if and only if $\text{pop} > 7$

Similar logic can be applied when $\text{rev}$ is negative.

```c++
class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
            if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
};
```

**Complexity Analysis**

- Time Complexity: $O(\log(x))$. There are roughly $\log_{10}(x)$ digits in $x$.
- Space Complexity: $O(1)$.

***

# 解决方案

## 方法：弹出和推入数字 & 溢出前进行检查

### 思路

我们可以一次构建反转整数的一位数字。在这样做的时候，我们可以预先检查向原整数附加另一位数字是否会导致溢出。

### 算法

反转整数的方法可以与反转字符串进行类比。

我们想重复“弹出” $x$ 的最后一位数字，并将它“推入”到 $\text{rev}$ 的后面。最后，$\text{rev}$ 将与 $x$ 相反。

要在没有辅助堆栈 / 数组的帮助下 “弹出” 和 “推入” 数字，我们可以使用数学方法。

```c
//pop operation:
pop = x % 10;
x /= 10;

//push operation:
temp = rev * 10 + pop;
rev = temp;
```

但是，这种方法很危险，因为当 $\text{temp} = \text{rev} \cdot 10 + \text{pop}$ 时会导致溢出。

幸运的是，事先检查这个语句是否会导致溢出很容易。

为了便于解释，我们假设 $\text{rev}$ 是正数。

1. 如果 $temp = \text{rev} \cdot 10 + \text{pop}$ 导致溢出，那么一定有 $\text{rev} \geq \frac{INTMAX}{10}$。
2. 如果 $\text{rev} > \frac{INTMAX}{10}$，那么 $temp = \text{rev} \cdot 10 + \text{pop}$ 一定会溢出。
3. 如果 $\text{rev} == \frac{INTMAX}{10}$，那么只要 $\text{pop} > 7$，$temp = \text{rev} \cdot 10 + \text{pop}$ 就会溢出。

当 $\text{rev}$ 为负时可以应用类似的逻辑。

```c++
class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
            if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
};
```

**复杂度分析**

- 时间复杂度：$O(\log(x))$，$x$ 中大约有 $\log_{10}(x)$ 位数字。
- 空间复杂度：$O(1)$。