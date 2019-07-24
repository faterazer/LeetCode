# 题目描述（Description）

## 20. Valid Parentheses

Given a string containing just the characters `(`, `)`, `{`, `}`, `[` and `]`, determine if the input string is valid.

An input string is valid if:

1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.

Note that an empty string is also considered valid.

Example 1:

```()
Input: "()"
Output: true
```

Example 2:

```()
Input: "()[]{}"
Output: true
```

Example 3:

```()
Input: "(]"
Output: false
```

Example 4:

```()
Input: "([)]"
Output: false
```

Example 5:

```()
Input: "{[]}"
Output: true
```

***

## 20. 有效的括号

给定一个只包括 `(`，`)`，`{`，`}`，`[`，`]` 的字符串，判断字符串是否有效。

有效字符串需满足：

1. 左括号必须用相同类型的右括号闭合。
2. 左括号必须以正确的顺序闭合。

注意空字符串可被认为是有效字符串。

示例 1:

```()
输入: "()"
输出: true
```

示例 2:

```()
输入: "()[]{}"
输出: true
```

示例 3:

```()
输入: "(]"
输出: false
```

示例 4:

```()
输入: "([)]"
输出: false
```

示例 5:

```()
输入: "{[]}"
输出: true
```
