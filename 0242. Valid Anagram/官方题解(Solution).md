# 官方题解

## 方法一：排序

### 算法

通过将 $s$ 的字母重新排列成 $t$ 来生成变位词。因此，如果 $t$ 是 $s$ 的变位词，对两个字符串进行排序将产生两个相同的字符串。此外，如果 $s$ 和 $t$ 的长度不同，$t$ 不能是 $s$ 的变位词，我们可以提前返回。

**Java:**

```java
public boolean isAnagram(String s, String t) {
    if (s.length() != t.length()) {
        return false;
    }
    char[] str1 = s.toCharArray();
    char[] str2 = t.toCharArray();
    Arrays.sort(str1);
    Arrays.sort(str2);
    return Arrays.equals(str1, str2);
}
```

### 复杂度分析

* 时间复杂度：$O(n \log n)$，假设 $n$ 是 $s$ 的长度，排序成本 $O(n\log n)$ 和比较两个字符串的成本 $O(n)$。排序时间占主导地位，总体时间复杂度为 $O(n \log n)$。
* 空间复杂度：$O(1)$，空间取决于排序实现，如果使用 `heapsort`，通常需要 $O(1)$ 辅助空间。注意，在 Java 中，`toCharArray()` 制作了一个字符串的拷贝，所以它花费 `O(n)` 额外的空间，但是我们忽略了这一复杂性分析，因为：
  * 这依赖于语言的细节。
  * 这取决于函数的设计方式。例如，可以将函数参数类型更改为 `char[]`。

## 方法二：哈希表

### 算法

为了检查 $t$ 是否是 $s$ 的重新排列，我们可以计算两个字符串中每个字母的出现次数并进行比较。因为 $s$ 和 $t$ 都只包含 $a$-$Z$ 的字母，所以一个简单的 26 位计数器表就足够了。

我们需要两个计数器数表进行比较吗？实际上不是，因为我们可以用一个计数器表计算 $s$ 字母的频率，用 $t$ 减少计数器表中的每个字母的计数器，然后检查计数器是否回到零。

**Java:**

```java
public boolean isAnagram(String s, String t) {
    if (s.length() != t.length()) {
        return false;
    }
    int[] counter = new int[26];
    for (int i = 0; i < s.length(); i++) {
        counter[s.charAt(i) - 'a']++;
        counter[t.charAt(i) - 'a']--;
    }
    for (int count : counter) {
        if (count != 0) {
            return false;
        }
    }
    return true;
}
```

或者我们可以先用计数器表计算 $s$，然后用 $t$ 减少计数器表中的每个字母的计数器。如果在任何时候计数器低于零，我们知道 $t$ 包含一个不在 $s$ 中的额外字母，并立即返回 FALSE。

**Java:**

```java
public boolean isAnagram(String s, String t) {
    if (s.length() != t.length()) {
        return false;
    }
    int[] table = new int[26];
    for (int i = 0; i < s.length(); i++) {
        table[s.charAt(i) - 'a']++;
    }
    for (int i = 0; i < t.length(); i++) {
        table[t.charAt(i) - 'a']--;
        if (table[t.charAt(i) - 'a'] < 0) {
            return false;
        }
    }
    return true;
}
```

### 复杂度分析

* 时间复杂度：$O(n)$。时间复杂度为 $O(n)$ 因为访问计数器表是一个固定的时间操作。
* 空间复杂度：$O(1)$。尽管我们使用了额外的空间，但是空间的复杂性是 $O(1)$，因为无论 $n$ 有多大，表的大小都保持不变。

### 进阶

如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？

### 解答：

使用哈希表而不是固定大小的计数器。想象一下，分配一个大的数组来适应整个 Unicode 字符范围，这个范围可能超过 100万。哈希表是一种更通用的解决方案，可以适应任何字符范围。

***

# Solution

## Approach #1 (Sorting) [Accepted]

### Algorithm

An anagram is produced by rearranging the letters of $s$ into $t$. Therefore, if $t$ is an anagram of $s$, sorting both strings will result in two identical strings. Furthermore, if $s$ and $t$ have different lengths, $t$ must not be an anagram of $s$ and we can return early.

**Java:**

```java
public boolean isAnagram(String s, String t) {
    if (s.length() != t.length()) {
        return false;
    }
    char[] str1 = s.toCharArray();
    char[] str2 = t.toCharArray();
    Arrays.sort(str1);
    Arrays.sort(str2);
    return Arrays.equals(str1, str2);
}
```

### Complexity analysis

* Time complexity: $O(n \log n)$. Assume that $n$ is the length of $s$, sorting costs $O(n\log n)$ and comparing two strings costs $O(n)$. Sorting time dominates and the overall time complexity is $O(n \log n)$.
* Space complexity: $O(1)$. Space depends on the sorting implementation which, usually, costs $O(1)$ auxiliary space if `heapsort` is used. Note that in Java, `toCharArray()` makes a copy of the string so it costs $O(n)$ extra space, but we ignore this for complexity analysis because:
  * It is a language dependent detail.
  * It depends on how the function is designed. For example, the function parameter types can be changed to `char[]`.

## Approach #2 (Hash Table) [Accepted]

### Algorithm

To examine if $t$ is a rearrangement of $s$, we can count occurrences of each letter in the two strings and compare them. Since both $s$ and $t$ contain only letters from $a$-$z$, a simple counter table of size 26 is suffice.

Do we need *two* counter tables for comparison? Actually no, because we could increment the counter for each letter in $s$ and decrement the counter for each letter in $t$, then check if the counter reaches back to zero.

**Java:**

```java
public boolean isAnagram(String s, String t) {
    if (s.length() != t.length()) {
        return false;
    }
    int[] counter = new int[26];
    for (int i = 0; i < s.length(); i++) {
        counter[s.charAt(i) - 'a']++;
        counter[t.charAt(i) - 'a']--;
    }
    for (int count : counter) {
        if (count != 0) {
            return false;
        }
    }
    return true;
}
```

Or we could first increment the counter for $s$, then decrement the counter for $t$. If at any point the counter drops below zero, we know that $t$ contains an extra letter not in $s$ and return false immediately.

**Java:**

```java
public boolean isAnagram(String s, String t) {
    if (s.length() != t.length()) {
        return false;
    }
    int[] table = new int[26];
    for (int i = 0; i < s.length(); i++) {
        table[s.charAt(i) - 'a']++;
    }
    for (int i = 0; i < t.length(); i++) {
        table[t.charAt(i) - 'a']--;
        if (table[t.charAt(i) - 'a'] < 0) {
            return false;
        }
    }
    return true;
}
```

### Complexity analysis

* Time complexity : $O(n)$. Time complexity is $O(n)$ because accessing the counter table is a constant time operation.
* Space complexity : $O(1)$. Although we do use extra space, the space complexity is $O(1)$ because the table's size stays constant no matter how large $n$ is.

### Follow up

What if the inputs contain unicode characters? How would you adapt your solution to such case?

### Answer

Use a hash table instead of a fixed size counter. Imagine allocating a large size array to fit the entire range of unicode characters, which could go up to [more than 1 million](https://stackoverflow.com/a/5928054/490463). A hash table is a more generic solution and could adapt to any range of characters.
