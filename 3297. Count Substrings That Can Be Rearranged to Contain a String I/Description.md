# 3297. Count Substrings That Can Be Rearranged to Contain a String I

You are given two strings `word1` and `word2`.

A string `x` is called **valid** if `x` can be rearranged to have `word2` as a *prefix*.

Return the total number of **valid** *substrings* of `word1`.

**Example 1:**

```()
Input: word1 = "bcca", word2 = "abc"

Output: 1

Explanation:

The only valid substring is "bcca" which can be rearranged to "abcc" having "abc" as a prefix.
```

**Example 2:**

```()
Input: word1 = "abcabc", word2 = "abc"

Output: 10

Explanation:

All the substrings except substrings of size 1 and size 2 are valid.
```

**Example 3:**

```()
Input: word1 = "abcabc", word2 = "aaabc"

Output: 0
```

**Constraints:**

- `1 <= word1.length <= 10^5`
- `1 <= word2.length <= 10^4`
- `word1` and `word2` consist only of lowercase English letters.
