# 3121. Count the Number of Special Characters II

You are given a string `word`. A letter `c` is called **special** if it appears **both** in lowercase and uppercase in `word`, and **every** lowercase occurrence of `c` appears before the **first** uppercase occurrence of `c`.

Return the number of **special** letters in `word`.

**Example 1:**

```text
Input: word = "aaAbcBC"

Output: 3

Explanation:

The special characters are 'a', 'b', and 'c'.
```

**Example 2:**

```text
Input: word = "abc"

Output: 0

Explanation:

There are no special characters in word.
```

**Example 3:**

```text
Input: word = "AbBCab"

Output: 0

Explanation:

There are no special characters in word.
```

**Constraints:**

- `1 <= word.length <= 2 * 10^5`
- `word` consists of only lowercase and uppercase English letters.
