# 题目描述 (Description)

## 38. Count and Say

The count-and-say sequence is the sequence of integers with the first five terms as following:

```()
1.       1
2.       11
3.       21
4.       1211
5.       111221
```

`1` is read off as `"one 1"` or `11`.

`11` is read off as `"two 1s"` or `21`.

`21` is read off as `"one 2, then one 1"` or `1211`.

Given an integer $n$ where $1 \leq n \leq 30$, generate the $n^{th}$ term of the count-and-say sequence.

Note: Each term of the sequence of integers will be represented as a string.

**Example 1:**

> **Input:** 1 \
> **Output:** "1"

**Example 2:**

> **Input:** 4 \
> **Output:** "1211"

***

## 38. 报数

报数序列是一个整数序列，按照其中的整数的顺序进行报数，得到下一个数。其前五项如下：

```()
1.       1
2.       11
3.       21
4.       1211
5.       111221
```

`1` 被读作  `"one 1"`  (`"一个一"`) , 即 `11`。

`11` 被读作 `"two 1s"` (`"两个一"`）, 即 `21`。

`21` 被读作 `"one 2"`,  `"one 1"` （`"一个二"` ,  `"一个一"`) , 即 `1211`。

给定一个正整数 $n$（$1 \leq n \leq 30$），输出报数序列的第 $n$ 项。

注意：整数顺序将表示为一个字符串。

**示例 1:**

> **输入:** 1 \
> **输出:** "1"

**示例 2:**

> **输入:** 4 \
> **输出:** "1211"
