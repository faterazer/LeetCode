# Solution

## Approach: Revert half of the number

### Intuition

The first idea that comes to mind is to convert the number into string, and check if the string is a palindrome, but this would require extra non-constant space for creating the string which is not allowed by the problem description.

Second idea would be reverting the number itself, and then compare the number with original number, if they are the same, then the number is a palindrome. However, if the reversed number is larger than `INT_MAX`, we will hit integer overflow problem.

Following the thoughts based on the second idea, to avoid the overflow issue of the reverted number, what if we only revert half of the `int` number? After all, the reverse of the last half of the palindrome should be the same as the first half of the number, if the number is a palindrome.

For example, if the input is `1221`, if we can revert the last part of the number "12**21**" from "**21**" to "**12**", and compare it with the first half of the number "12", since 12 is the same as 12, we know that the number is a palindrome.

Let's see how we could translate this idea into an algorithm.

### Algorithm

First of all we should take care of some edge cases. All negative numbers are not palindrome, for example: -123 is not a palindrome since the '-' does not equal to '3'. So we can return false for all negative numbers.

Now let's think about how to revert the last half of the number. For number `1221`, if we do `1221 % 10`, we get the last digit `1`, to get the second to the last digit, we need to remove the last digit from `1221`, we could do so by dividing it by 10, `1221 / 10 = 122`. Then we can get the last digit again by doing a modulus by 10, `122 % 10 = 2`, and if we multiply the last digit by 10 and add the second last digit, `1 * 10 + 2 = 12`, it gives us the reverted number we want. Continuing this process would give us the reverted number with more digits.

Now the question is, how do we know that we've reached the half of the number?

Since we divided the number by 10, and multiplied the reversed number by 10, when the original number is less than the reversed number, it means we've processed half of the number digits.

```c#
public class Solution {
    public bool IsPalindrome(int x) {
        // Special cases:
        // As discussed above, when x < 0, x is not a palindrome.
        // Also if the last digit of the number is 0, in order to be a palindrome,
        // the first digit of the number also needs to be 0.
        // Only 0 satisfy this property.
        if(x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int revertedNumber = 0;
        while(x > revertedNumber) {
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;
        }

        // When the length is an odd number, we can get rid of the middle digit by revertedNumber/10
        // For example when the input is 12321, at the end of the while loop we get x = 12, revertedNumber = 123,
        // since the middle digit doesn't matter in palidrome(it will always equal to itself), we can simply get rid of it.
        return x == revertedNumber || x == revertedNumber/10;
    }
}
```

### Complexity Analysis

- Time complexity : $O(\log_{10}^{(n)})$. We divided the input by 10 for every iteration, so the time complexity is $O(\log_{10}^{(n)})$.
- Space complexity : $O(1)$.

***

# 解决方案

## 方法：反转一半数字

### 思路

映入脑海的第一个想法是将数字转换为字符串，并检查字符串是否为回文。但是，这需要额外的非常量空间来创建问题描述中所不允许的字符串。

第二个想法是将数字本身反转，然后将反转后的数字与原始数字进行比较，如果它们是相同的，那么这个数字就是回文。 但是，如果反转后的数字大于 `INT_MAX`，我们将遇到整数溢出问题。

按照第二个想法，为了避免数字反转可能导致的溢出问题，为什么不考虑只反转 $\text{int}$ 数字的一半？毕竟，如果该数字是回文，其后半部分反转后应该与原始数字的前半部分相同。

例如，输入 `1221`，我们可以将数字“12**21**”的后半部分从“**21**”反转为“**12**”，并将其与前半部分“12”进行比较，因为二者相同，我们得知数字 `1221` 是回文。

让我们看看如何将这个想法转化为一个算法。

### 算法

首先，我们应该处理一些临界情况。所有负数都不可能是回文，例如：-123 不是回文，因为 `-` 不等于 `3`。所以我们可以对所有负数返回 false。

现在，让我们来考虑如何反转后半部分的数字。 对于数字 `1221`，如果执行 `1221 % 10`，我们将得到最后一位数字 `1`，要得到倒数第二位数字，我们可以先通过除以 10 把最后一位数字从 `1221` 中移除，`1221 / 10 = 122`，再求出上一步结果除以10的余数，`122 % 10 = 2`，就可以得到倒数第二位数字。如果我们把最后一位数字乘以10，再加上倒数第二位数字，`1 * 10 + 2 = 12`，就得到了我们想要的反转后的数字。 如果继续这个过程，我们将得到更多位数的反转数字。

现在的问题是，我们如何知道反转数字的位数已经达到原始数字位数的一半？

我们将原始数字除以 10，然后给反转后的数字乘上 10，所以，当原始数字小于反转后的数字时，就意味着我们已经处理了一半位数的数字。

 ```c#
public class Solution {
    public bool IsPalindrome(int x) {
        // 特殊情况：
        // 如上所述，当 x < 0 时，x 不是回文数。
        // 同样地，如果数字的最后一位是 0，为了使该数字为回文，
        // 则其第一位数字也应该是 0
        // 只有 0 满足这一属性
        if(x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int revertedNumber = 0;
        while(x > revertedNumber) {
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;
        }

        // 当数字长度为奇数时，我们可以通过 revertedNumber/10 去除处于中位的数字。
        // 例如，当输入为 12321 时，在 while 循环的末尾我们可以得到 x = 12，revertedNumber = 123，
        // 由于处于中位的数字不影响回文（它总是与自己相等），所以我们可以简单地将其去除。
        return x == revertedNumber || x == revertedNumber/10;
    }
}
 ```

**复杂度分析**

- 时间复杂度：$O(\log_{10}(n))$， 对于每次迭代，我们会将输入除以10，因此时间复杂度为 $O(\log_{10}(n))$。
- 空间复杂度：$O(1)$。