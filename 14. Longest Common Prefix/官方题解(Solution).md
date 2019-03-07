# Solution

## Approach 1: Horizontal scanning

### Intuition

For a start we will describe a simple way of finding the longest prefix shared by a set of strings $LCP(S_1 \ldots S_n)$. We will use the observation that :

$LCP(S_1 \ldots S_n) = LCP(LCP(LCP(S_1, S_2),S_3),\ldots S_n)$

### Algorithm

To employ this idea, the algorithm iterates through the strings $[S_1 \ldots S_n]$, finding at each iteration $i$ the longest common prefix of strings $LCP(S_1 \ldots S_i)$ When $LCP(S_1 \ldots S_i)$ is an empty string, the algorithm ends. Otherwise after $n$ iterations, the algorithm returns $LCP(S_1 \ldots S_n)$.

![Figure 1. Finding the longest common prefix (Horizontal scanning)](./image/figure1.png)

```java
 public String longestCommonPrefix(String[] strs) {
    if (strs.length == 0) return "";
    String prefix = strs[0];
    for (int i = 1; i < strs.length; i++)
        while (strs[i].indexOf(prefix) != 0) {
            prefix = prefix.substring(0, prefix.length() - 1);
            if (prefix.isEmpty()) return "";
        }        
    return prefix;
}
```

### Complexity Analysis

- Time complexity : $O(S)$, where S is the sum of all characters in all strings.

  In the worst case all $n$ strings are the same. The algorithm compares the string $S1$ with the other strings $[S_2 \ldots S_n]$ There are $S$ character comparisons, where $S$ is the sum of all characters in the input array.

- Space complexity : $O(1)$. We only used constant extra space. 

## Approach 2: Vertical scanning

### Algorithm

Imagine a very short string is at the end of the array. The above approach will still do $S$ comparisons. One way to optimize this case is to do vertical scanning. We compare characters from top to bottom on the same column (same character index of the strings) before moving on to the next column.

```java
public String longestCommonPrefix(String[] strs) {
    if (strs == null || strs.length == 0) return "";
    for (int i = 0; i < strs[0].length() ; i++){
        char c = strs[0].charAt(i);
        for (int j = 1; j < strs.length; j ++) {
            if (i == strs[j].length() || strs[j].charAt(i) != c)
                return strs[0].substring(0, i);             
        }
    }
    return strs[0];
}	
```

### Complexity Analysis

- Time complexity : $O(S)$ , where S is the sum of all characters in all strings. In the worst case there will be $n$ equal strings with length $m$ and the algorithm performs $S = m ∗ n$ character comparisons. Even though the worst case is still the same as **Approach 1**, in the best case there are at most $n * minLen$ comparisons where $minLen$ is the length of the shortest string in the array.
- Space complexity : $O(1)$. We only used constant extra space. 

## Approach 3: Divide and conquer

### intuition

The idea of the algorithm comes from the associative property of LCP operation. We notice that : $LCP(S_1 \ldots S_n) = LCP(LCP(S_1 \ldots S_k), LCP (S_{k+1} \ldots S_n))$ , where $LCP(S_1 \ldots S_n)$ is the longest common prefix in set of strings $[S_1 \ldots S_n] , 1 < k < n$

### Algorithm

To apply the observation above, we use divide and conquer technique, where we split the $LCP(S_i \ldots S_j)$ problem into two subproblems $LCP(S_i \ldots S_{mid})$ and $LCP(S_{mid+1} \ldots S_j)$, where `mid` is $\frac{i + j}{2}$. We use their solutions `lcpLeft` and `lcpRight` to construct the solution of the main problem $LCP(S_i \ldots S_j)$. To accomplish this we compare one by one the characters of `lcpLeft` and `lcpRight` till there is no character match. The found common prefix of `lcpLeft` and `lcpRight` is the solution of the $LCP(S_i \ldots S_j)$.

![Figure 2. Finding the longest common prefix of strings using divide and conquer technique](./image/figure2.png)

```java
public String longestCommonPrefix(String[] strs) {
    if (strs == null || strs.length == 0)
        return ""; 
    return longestCommonPrefix(strs, 0 , strs.length - 1);
}

private String longestCommonPrefix(String[] strs, int l, int r) {
    if (l == r) {
        return strs[l];
    }
    else {
        int mid = (l + r)/2;
        String lcpLeft =   longestCommonPrefix(strs, l , mid);
        String lcpRight =  longestCommonPrefix(strs, mid + 1,r);
        return commonPrefix(lcpLeft, lcpRight);
   }
}

String commonPrefix(String left,String right) {
    int min = Math.min(left.length(), right.length());       
    for (int i = 0; i < min; i++) {
        if ( left.charAt(i) != right.charAt(i) )
            return left.substring(0, i);
    }
    return left.substring(0, min);
}
```

### Complexity Analysis

In the worst case we have $n$ equal strings with length $m$

- Time complexity : $O(S)$, where $S$ is the number of all characters in the array, $S = m*n$ Time complexity is $2 \cdot T\left ( \frac{n}{2} \right ) + O(m)$. Therefore time complexity is $O(S)$. In the best case this algorithm performs $O(minLen \cdot n)$ comparisons, where $minLen$ is the shortest string of the array.

- Space complexity : $O(m \cdot log(n))$

  There is a memory overhead since we store recursive calls in the execution stack. There are $log(n)$ recursive calls, each store need $m$ space to store the result, so space complexity is $O(m \cdot log(n))$.

## Approach 4: Binary search

The idea is to apply binary search method to find the string with maximum value `L`, which is common prefix of all of the strings. The algorithm searches space is the interval $(0 \ldots minLen)$, where `minLen` is minimum string length and the maximum possible common prefix. Each time search space is divided in two equal parts, one of them is discarded, because it is sure that it doesn't contain the solution. There are two possible cases: `S[1...mid]` is not a common string. This means that for each `j > i S[1..j]` is not a common string and we discard the second half of the search space. `S[1...mid]` is common string. This means that for for each `i < j S[1..i]` is a common string and we discard the first half of the search space, because we try to find longer common prefix.

![Figure 3. Finding the longest common prefix of strings using binary search technique](./image/figure3.png)

```java

```

### Complexity Analysis

In the worst case we have $n$ equal strings with length $m$

- Time complexity : $O(S \cdot log(n))$, where $S$ is the sum of all characters in all strings.

  The algorithm makes $log(n)$ iterations, for each of them there are $S = m*n$ comparisons, which gives in total $O(S \cdot log(n))$ time complexity.

  > But it seems to me that time complexity is $O(S * log(m))$

- Space complexity : $O(1)$. We only used constant extra space. 

## Further Thoughts / Follow up

Let's take a look at a slightly different problem:

> Given a set of keys $S = [S_1,S_2 \ldots S_n]$, find the longest common prefix among a string `q` and S. This LCP query will be called frequently.

We could optimize LCP queries by storing the set of keys S in a Trie. For more information about Trie, please see this article [Implement a trie (Prefix trie)](https://leetcode.com/articles/implement-trie-prefix-tree/). In a Trie, each node descending from the root represents a common prefix of some keys. But we need to find the longest common prefix of a string `q` and all key strings. This means that we have to find the deepest path from the root, which satisfies the following conditions: 

- It is prefix of query string `q`.
- Each node along the path must contain only one child element. Otherwise the found path will not be a common prefix among all strings. 
- The path doesn't comprise of nodes which are marked as end of key. Otherwise the path couldn't be a prefix a of key which is shorter than itself.

### Algorithm

The only question left, is how to find the deepest path in the Trie, that fulfills the requirements above. The most effective way is to build a trie from $[S_1 \ldots S_n]$ strings. Then find the prefix of query string `q` in the Trie. We traverse the Trie from the root, till it is impossible to continue the path in the Trie because one of the conditions above is not satisfied.

![Figure 4. Finding the longest common prefix of strings using Trie](./image/figure4.png)

```java
public String longestCommonPrefix(String q, String[] strs) {
    if (strs == null || strs.length == 0)
         return "";  
    if (strs.length == 1)
         return strs[0];
    Trie trie = new Trie();      
    for (int i = 1; i < strs.length ; i++) {
        trie.insert(strs[i]);
    }
    return trie.searchLongestPrefix(q);
}

class TrieNode {

    // R links to node children
    private TrieNode[] links;

    private final int R = 26;

    private boolean isEnd;

    // number of children non null links
    private int size;    
    public void put(char ch, TrieNode node) {
        links[ch -'a'] = node;
        size++;
    }

    public int getLinks() {
        return size;
    }
    //assume methods containsKey, isEnd, get, put are implemented as it is described
   //in  https://leetcode.com/articles/implement-trie-prefix-tree/)
}

public class Trie {

    private TrieNode root;

    public Trie() {
        root = new TrieNode();
    }

//assume methods insert, search, searchPrefix are implemented as it is described
//in  https://leetcode.com/articles/implement-trie-prefix-tree/)
    private String searchLongestPrefix(String word) {
        TrieNode node = root;
        StringBuilder prefix = new StringBuilder();
        for (int i = 0; i < word.length(); i++) {
            char curLetter = word.charAt(i);
            if (node.containsKey(curLetter) && (node.getLinks() == 1) && (!node.isEnd())) {
                prefix.append(curLetter);
                node = node.get(curLetter);
            }
            else
                return prefix.toString();

         }
         return prefix.toString();
    }
}
```

### Complexity Analysis

In the worst case query $q$ has length $m$ and it is equal to all $n$ strings of the array.

- Time complexity : preprocessing $O(S)$, where $S$ is the number of all characters in the array, LCP query $O(m)$.

  Trie build has $O(S)$ time complexity. To find the common prefix of $q$ in the Trie takes in the worst case $O(m)$.

- Space complexity : $O(S)$. We only used additional $S$ extra space for the Trie.

***

# 解决方案

## 方法一：水平扫描

### 思路

首先，我们将描述一种查找一组字符串的最长公共前缀 $LCP(S_1 \ldots S_n)$ 的简单方法。 我们将会用到这样的结论：
$$
LCP(S_1 \ldots S_n) = LCP(LCP(LCP(S_1, S_2),S_3),\ldots S_n).
$$

### 算法

为了运用这种思想，算法要依次遍历字符串 $[S_1 \ldots S_n]$，当遍历到第 $i$ 个字符串的时候，找到最长公共前缀 $LCP(S_1 \ldots S_i)$。当 $LCP(S_1 \ldots S_i)$ 是一个空串的时候，算法就结束了。 否则，在执行了 $n$ 次遍历之后，算法就会返回最终答案 $LCP(S_1 \ldots S_n)$。

![图 1. 查找最长公共前缀 (水平扫描法)](./image/figure1.png)

```java
 public String longestCommonPrefix(String[] strs) {
    if (strs.length == 0) return "";
    String prefix = strs[0];
    for (int i = 1; i < strs.length; i++)
        while (strs[i].indexOf(prefix) != 0) {
            prefix = prefix.substring(0, prefix.length() - 1);
            if (prefix.isEmpty()) return "";
        }        
    return prefix;
}
```

 ### 复杂度分析

- 时间复杂度：$O(S)$，S 是所有字符串中字符数量的总和。

  最坏的情况下，$n$ 个字符串都是相同的。算法会将 $S1$ 与其他字符串 $[S_2 \ldots S_n]$ 都做一次比较。这样就会进行 $S$ 次字符比较，其中 $S$ 是输入数据中所有字符数量。

- 空间复杂度：$O(1)$， 我们只需要使用常数级别的额外空间。

## 算法二：垂直扫描

### 算法

想象数组的末尾有一个非常短的字符串， 使用上述方法依旧会进行 $S$ 次比较。 优化这类情况的一种方法就是垂直扫描。 我们从前往后枚举字符串的每一列，先比较每个字符串相同列上的字符（即不同字符串相同下标的字符）然后再进行对下一列的比较。 

```java
public String longestCommonPrefix(String[] strs) {
    if (strs == null || strs.length == 0) return "";
    for (int i = 0; i < strs[0].length() ; i++){
        char c = strs[0].charAt(i);
        for (int j = 1; j < strs.length; j ++) {
            if (i == strs[j].length() || strs[j].charAt(i) != c)
                return strs[0].substring(0, i);             
        }
    }
    return strs[0];
}
```

### 复杂度分析

- 时间复杂度：$O(S)$，S 是所有字符串中字符数量的总和。

  最坏情况下，输入数据为 $n$ 个长度为 $m$ 的相同字符串，算法会进行 $S = m*n$ 次比较。可以看到最坏情况下，本算法的效率与算法一相同，但是最好的情况下，算法只需要进行 $n∗minLen$ 次比较，其中 $minLen$ 是数组中最短字符串的长度。

- 空间复杂度：$O(1)$， 我们只需要使用常数级别的额外空间。

## 算法三：分治

### 思路

这个算法的思路来自于 LCP 操作的结合律。我们可以发现：
$$
LCP(S_1 \ldots S_n) = LCP(LCP(S_1 \ldots S_k), LCP (S_{k+1} \ldots S_n))
$$
其中 $LCP(S_1 \ldots S_n)$ 是字符串 $[S_1 \ldots S_n]$ 的最长公共前缀，$1 < k < n$。

### 算法

为了应用上述的结论，我们使用分治的技巧，将原问题 $LCP(S_i\cdots S_j)$ 分成两个子问题 $LCP(S_i\cdots S_{mid})$ 与 $LCP(S_{mid+1}, S_j)$，其中 $mid=\frac{i+j}{2}$。 我们用子问题的解 `lcpLeft` 与 `lcpRight`构造原问题的解 $LCP(S_i \cdots S_j)$。 从头到尾挨个比较 `lcpLeft` 与 `lcpRight` 中的字符，直到不能再匹配为止。 计算所得的 `lcpLeft` 与 `lcpRight` 最长公共前缀就是原问题的解 $LCP(S_i\cdots S_j)$。

![图 2. 查找最长公共前缀的分治方法](./image/figure2.png)

```java
public String longestCommonPrefix(String[] strs) {
    if (strs == null || strs.length == 0) return "";    
        return longestCommonPrefix(strs, 0 , strs.length - 1);
}

private String longestCommonPrefix(String[] strs, int l, int r) {
    if (l == r) {
        return strs[l];
    }
    else {
        int mid = (l + r)/2;
        String lcpLeft =   longestCommonPrefix(strs, l , mid);
        String lcpRight =  longestCommonPrefix(strs, mid + 1,r);
        return commonPrefix(lcpLeft, lcpRight);
   }
}

String commonPrefix(String left,String right) {
    int min = Math.min(left.length(), right.length());       
    for (int i = 0; i < min; i++) {
        if ( left.charAt(i) != right.charAt(i) )
            return left.substring(0, i);
    }
    return left.substring(0, min);
}
```

### 复杂度分析

最坏情况下，我们有 $n$ 个长度为 $m$ 的相同字符串。

- 时间复杂度：$O(S)$，$S$ 是所有字符串中字符数量的总和，$S=m∗n$。

  时间复杂度的递推式为 $T(n)=2\cdot T(\frac{n}{2})+O(m)$， 化简后可知其就是 $O(S)$。最好情况下，算法会进行 $minLen\cdot n$ 次比较，其中 $minLen$ 是数组中最短字符串的长度。

- 空间复杂度：$O(m \cdot log(n))$

  内存开支主要是递归过程中使用的栈空间所消耗的。 一共会进行 $log(n)$ 次递归，每次需要 $m$ 的空间存储返回结果，所以空间复杂度为 $O(m\cdot log(n))$。

## 方法四：二分查找

这个想法是应用二分查找法找到所有字符串的公共前缀的最大长度 `L`。算法的查找区间是 $(0 \ldots minLen)$，其中 `minLen` 是输入数据中最短的字符串的长度，同时也是答案的最长可能长度。每一次将查找区间一分为二，然后丢弃一定不包含最终答案的那一个。算法进行的过程中一共会出现两种可能情况：

- `S[1...mid]` 不是所有串的公共前缀。 这表明对于所有的 `j > i S[1..j]` 也不是公共前缀，于是我们就可以丢弃后半个查找区间。
- `S[1...mid]` 是所有串的公共前缀。 这表示对于所有的 `i < j S[1..i]` 都是可行的公共前缀，因为我们要找最长的公共前缀，所以我们可以把前半个查找区间丢弃。

![图 3. 使用二分查找法寻找最长公共前缀](./image/figure3.png)

```java
public String longestCommonPrefix(String[] strs) {
    if (strs == null || strs.length == 0)
        return "";
    int minLen = Integer.MAX_VALUE;
    for (String str : strs)
        minLen = Math.min(minLen, str.length());
    int low = 1;
    int high = minLen;
    while (low <= high) {
        int middle = (low + high) / 2;
        if (isCommonPrefix(strs, middle))
            low = middle + 1;
        else
            high = middle - 1;
    }
    return strs[0].substring(0, (low + high) / 2);
}

private boolean isCommonPrefix(String[] strs, int len){
    String str1 = strs[0].substring(0,len);
    for (int i = 1; i < strs.length; i++)
        if (!strs[i].startsWith(str1))
            return false;
    return true;
}
```

### 复杂度分析

最坏情况下，我们有 $n$ 个长度为 $m$ 的相同字符串。

- 时间复杂度：$O(S \cdot log(n))$，其中 $S$ 所有字符串中字符数量的总和。

  算法一共会进行 $log(n)$ 次迭代，每次一都会进行 $S=m∗n$ 次比较，所以总时间复杂度为 $O(S \cdot log(n))$。

  > 我的计算，时间复杂度应该是 $O(S * \lg{n})$，其中 $\lg$ 以 2 为底数。

- 空间复杂度：$O(1)$，我们只需要使用常数级别的额外空间。 

## 更进一步

让我们看一个有些不同的问题：

> 给定一些键值字符串 $S = [S_1,S_2 \ldots S_n]$，我们要找到字符串 `q` 与 S 的最长公共前缀。这样的查询操作可能会非常频繁。

我们可以通过将所有的键值 S 存储到一颗字典树中来优化最长公共前缀查询操作。如果你想获得更多关于字典树的信息,可以查看这篇文章 [Implement a trie (Prefix trie)](https://leetcode.com/articles/implement-trie-prefix-tree/) 。在字典树中，从根向下的每一个节点都代表一些键值的公共前缀。但是我们需要找到字符串 `q` 和所有键值字符串的最长公共前缀。这意味着我们需要从根找到一条最深的路径，满足以下条件：

- 这是所查询的字符串 `q` 的一个前缀。
- 路径上的每一个节点都有且仅有一个孩子。否则，找到的路径就不是所有字符串的公共前缀。
- 路径不包含被标记成某一个键值字符串结尾的节点。因为最长公共前缀不可能比某个字符串本身长。

### 算法

最后的问题就是如何找到字典树中满足上述所有要求的最深节点。最有效的方法就是建立一颗包含字符串 $[S_1 \ldots S_n]$ 的字典树。然后在这颗树中匹配 `q` 的前缀。我们从根节点遍历这颗字典树，直到因为不能满足某个条件而不能再遍历为止。

![图 4. 使用字典树查找最长公共前缀](./image/figure4.png)

```java
public String longestCommonPrefix(String q, String[] strs) {
    if (strs == null || strs.length == 0)
         return "";  
    if (strs.length == 1)
         return strs[0];
    Trie trie = new Trie();      
    for (int i = 1; i < strs.length ; i++) {
        trie.insert(strs[i]);
    }
    return trie.searchLongestPrefix(q);
}

class TrieNode {

    // 子节点的链接数组
    private TrieNode[] links;

    private final int R = 26;

    private boolean isEnd;

    // 非空子节点的数量
    private int size;    
    public void put(char ch, TrieNode node) {
        links[ch -'a'] = node;
        size++;
    }

    public int getLinks() {
        return size;
    }
    // 假设方法 containsKey、isEnd、get、put 都已经实现了
    // 可以参考文章：https://leetcode.com/articles/implement-trie-prefix-tree/
}

public class Trie {

    private TrieNode root;

    public Trie() {
        root = new TrieNode();
    }

// 假设方法 insert、search、searchPrefix 都已经实现了
// 可以参考文章：https://leetcode.com/articles/implement-trie-prefix-tree/
    private String searchLongestPrefix(String word) {
        TrieNode node = root;
        StringBuilder prefix = new StringBuilder();
        for (int i = 0; i < word.length(); i++) {
            char curLetter = word.charAt(i);
            if (node.containsKey(curLetter) && (node.getLinks() == 1) && (!node.isEnd())) {
                prefix.append(curLetter);
                node = node.get(curLetter);
            }
            else
                return prefix.toString();

         }
         return prefix.toString();
    }
}
```

### 复杂度分析

最坏情况下查询字符串 $q$ 的长度为 $m$ 并且它与数组中 $n$ 个字符串均相同。

- 时间复杂度：预处理过程 $O(S)$，其中 $S$ 数组里所有字符串中字符数量的总和，最长公共前缀查询操作的复杂度为 $O(m)$。

  建立字典树的时间复杂度为 $O(S)$。在字典树中查找字符串 $q$ 的最长公共前缀在最坏情况下需要 $O(m)$ 的时间。

- 空间复杂度：$O(S)$，我们只需要使用额外的 $S$ 空间建立字典树。