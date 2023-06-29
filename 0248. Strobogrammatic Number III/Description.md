# 248. Strobogrammatic Number III

Given two strings low and high that represent two integers `low` and `high` where `low <= high`, return *the number of **strobogrammatic numbers** in the range* `[low, high]`.

A **strobogrammatic number** is a number that looks the same when rotated `180` degrees (looked at upside down).

**Example 1:**

```()
Input: low = "50", high = "100"
Output: 3
```

**Example 2:**

```()
Input: low = "0", high = "0"
Output: 1
```

**Constraints:**

- `1 <= low.length, high.length <= 15`
- `low` and `high` consist of only digits.
- `low <= high`
- `low` and `high` do not contain any leading zeros except for zero itself.
