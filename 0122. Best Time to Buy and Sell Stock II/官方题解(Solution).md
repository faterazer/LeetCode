# 官方题解

## 摘要

我们必须确定通过交易能够获得的最大利润（对于交易次数没有限制）。为此，我们需要找出那些共同使得利润最大化的买入及卖出价格。

## 方法一：暴力法

这种情况下，我们只需要计算与所有可能的交易组合相对应的利润，并找出它们中的最大利润。

Java:

```java
class Solution {
    public int maxProfit(int[] prices) {
        return calculate(prices, 0);
    }

    public int calculate(int prices[], int s) {
        if (s >= prices.length)
            return 0;
        int max = 0;
        for (int start = s; start < prices.length; start++) {
            int maxprofit = 0;
            for (int i = start + 1; i < prices.length; i++) {
                if (prices[start] < prices[i]) {
                    int profit = calculate(prices, i + 1) + prices[i] - prices[start];
                    if (profit > maxprofit)
                        maxprofit = profit;
                }
            }
            if (maxprofit > max)
                max = maxprofit;
        }
        return max;
    }
}
```

### 复杂度分析

* 时间复杂度：$O(n^n)$，调用递归函数 $n^n$ 次。
* 空间复杂度：$O(n)$，递归的深度为 $n$。

## 方法二：峰谷法

### 算法

假设给定的数组为：`[7, 1, 5, 3, 6, 4]`。

如果我们在图表上绘制给定数组中的数字，我们将会得到：

![Maximum Profit](images/image1.png)

如果我们分析图表，那么我们的兴趣点是连续的峰和谷。

用数学语言描述为：

$$
TotalProfit = \sum_i (height(peak_i) - height(valley_i))
$$

关键是我们需要考虑到紧跟谷的每一个峰值以最大化利润。如果我们试图跳过其中一个峰值来获取更多利润，那么我们最终将失去其中一笔交易中获得的利润，从而导致总利润的降低。

例如，在上述情况下，如果我们跳过 $peak_i$ 和 $valley_j$ 试图通过考虑差异较大的点以获取更多的利润，获得的净利润总是会小与包含它们而获得的净利润，因为 $C$ 总是小于 $A+B$。

Java:

```java
class Solution {
    public int maxProfit(int[] prices) {
        int i = 0;
        int valley = prices[0];
        int peak = prices[0];
        int maxprofit = 0;
        while (i < prices.length - 1) {
            while (i < prices.length - 1 && prices[i] >= prices[i + 1])
                i++;
            valley = prices[i];
            while (i < prices.length - 1 && prices[i] <= prices[i + 1])
                i++;
            peak = prices[i];
            maxprofit += peak - valley;
        }
        return maxprofit;
    }
}
```

### 复杂度分析

* 时间复杂度: $O(n)$。遍历一次。
* 空间复杂度: $O(1)$。需要常量的空间。

## 方法三：简单的一次遍历

### 算法

该解决方案遵循 *方法二* 的本身使用的逻辑，但有一些轻微的变化。在这种情况下，我们可以简单地继续在斜坡上爬升并持续增加从连续交易中获得的利润，而不是在谷之后寻找每个峰值。最后，我们将有效地使用峰值和谷值，但我们不需要跟踪峰值和谷值对应的成本以及最大利润，但我们可以直接继续增加加数组的连续数字之间的差值，如果第二个数字大于第一个数字，我们获得的总和将是最大利润。这种方法将简化解决方案。
这个例子可以更清楚地展现上述情况：

`[1, 7, 2, 3, 6, 7, 6, 7]`

与此数组对应的图形是：

![Maximum Profit](images/image2.png)

从上图中，我们可以观察到 $A+B+C$ 的和等于差值 $D$ 所对应的连续峰和谷的高度之差。

Java:

```java
class Solution {
    public int maxProfit(int[] prices) {
        int maxprofit = 0;
        for (int i = 1; i < prices.length; i++) {
            if (prices[i] > prices[i - 1])
                maxprofit += prices[i] - prices[i - 1];
        }
        return maxprofit;
    }
}
```

### 复杂度分析

* 时间复杂度: $O(n)$，遍历一次。
* 空间复杂度: $O(1)$，需要常量的空间。

***

# Solution

## Summary

We have to determine the maximum profit that can be obtained by making the transactions (no limit on the number of transactions done). For this we need to find out those sets of buying and selling prices which together lead to the maximization of profit.

## Approach 1: Brute Force

In this case, we simply calculate the profit corresponding to all the possible sets of transactions and find out the maximum profit out of them.

Java:

```java
class Solution {
    public int maxProfit(int[] prices) {
        return calculate(prices, 0);
    }

    public int calculate(int prices[], int s) {
        if (s >= prices.length)
            return 0;
        int max = 0;
        for (int start = s; start < prices.length; start++) {
            int maxprofit = 0;
            for (int i = start + 1; i < prices.length; i++) {
                if (prices[start] < prices[i]) {
                    int profit = calculate(prices, i + 1) + prices[i] - prices[start];
                    if (profit > maxprofit)
                        maxprofit = profit;
                }
            }
            if (maxprofit > max)
                max = maxprofit;
        }
        return max;
    }
}
```

### Complexity Analysis

* Time complexity: $O(n^n)$. Recursive function is called $n^n$ times.
* Space complexity: $(n)$. Depth of recursion is $n$.

## Approach 2: Peak Valley Approach

### Algorithm

Say the given array is: `[7, 1, 5, 3, 6, 4]`.

If we plot the numbers of the given array on a graph, we get:

![Maximum Profit](images/image1.png)

If we analyze the graph, we notice that the points of interest are the consecutive valleys and peaks.

Mathematically speaking:

$$
TotalProfit = \sum_i (height(peak_i) - height(valley_i))
$$

The key point is we need to consider every peak immediately following a valley to maximize the profit. In case we skip one of the peaks (trying to obtain more profit), we will end up losing the profit over one of the transactions leading to an overall lesser profit.

For example, in the above case, if we skip $peak_i$ and $valley_j$ trying to obtain more profit by considering points with more difference in heights, the net profit obtained will always be lesser than the one obtained by including them, since $C$ will always be lesser than $A+B$.

Java:

```java
class Solution {
    public int maxProfit(int[] prices) {
        int i = 0;
        int valley = prices[0];
        int peak = prices[0];
        int maxprofit = 0;
        while (i < prices.length - 1) {
            while (i < prices.length - 1 && prices[i] >= prices[i + 1])
                i++;
            valley = prices[i];
            while (i < prices.length - 1 && prices[i] <= prices[i + 1])
                i++;
            peak = prices[i];
            maxprofit += peak - valley;
        }
        return maxprofit;
    }
}
```

### Complexity Analysis

* Time complexity: $O(n)$. Single pass.
* Space complexity: $O(1)$. Constant space required.

## Approach 3: Simple One Pass

### Algorithm

This solution follows the logic used in *Approach 2* itself, but with only a slight variation. In this case, instead of looking for every peak following a valley, we can simply go on crawling over the slope and keep on adding the profit obtained from every consecutive transaction. In the end,we will be using the peaks and valleys effectively, but we need not track the costs corresponding to the peaks and valleys along with the maximum profit, but we can directly keep on adding the difference between the consecutive numbers of the array if the second number is larger than the first one, and at the total sum we obtain will be the maximum profit. This approach will simplify the solution. This can be made clearer by taking this example:

`[1, 7, 2, 3, 6, 7, 6, 7]`

The graph corresponding to this array is:

![Maximum Profit](images/image2.png)

From the above graph, we can observe that the sum $A+B+C$ is equal to the difference $D$ corresponding to the difference between the heights of the consecutive peak and valley.

Java:

```java
class Solution {
    public int maxProfit(int[] prices) {
        int maxprofit = 0;
        for (int i = 1; i < prices.length; i++) {
            if (prices[i] > prices[i - 1])
                maxprofit += prices[i] - prices[i - 1];
        }
        return maxprofit;
    }
}
```

### Complexity Analysis

* Time complexity: $O(n)$. Single pass.
* Space complexity: $O(1)$. Constant space needed.
