# 官方题解

本文面向初学者，介绍了以下概念：循环不变式, 线性查找，排序和哈希表。

## 方法一：朴素线性查找 【超时】

## 直觉

对于一个有 $n$ 个整数的数组，一共有 $C(n, 2) = \frac{n(n+1)}{2}$ 对整数。因此，我们可以对所有的 $\frac{n(n+1)}{2}$ 对进行检测，看它们是否相同。

## 算法

为了实现这个思路，我们使用线性查找算法，这是最简单的查找算法。线性查找是一种检查特定值是否在列表中的算法，做法是依次逐个检查列表中的元素，直到找到满足的元素。

对于本问题，我们循环遍历全部 $n$ 个数。对于第 $i$ 个整数 `nums[i]`，我们对前 `i-1` 个整数查找 `nums[i]` 的重复值。若找到，则返回 True; 否则继续。在程序最后，返回 False。

为了证明算法的正确性，我们定义了循环不变式。循环不变式是指在每次迭代前和后均保持不变的性质。了解循环不变式对理解循环的意义十分重要。下面就是**循环不变式**:

> 在下一次搜索之前,搜索过的整数中没有重复的整数。

循环不变式在循环之前为真，因为还没有搜索过的整数。每次循环，我们查找当前元素的任何可能重复。如果发现重复项,则函数返回 True 退出；如果没有发现，则不变式仍然成立。

因此，如果循环结束，循环不变式说明全部 $n$ 个整数中不存在重复元素。

**Java:**

```java
public boolean containsDuplicate(int[] nums) {
    for (int i = 0; i < nums.length; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[j] == nums[i]) return true;  
        }
    }
    return false;
}
// Time Limit Exceeded
```

### 复杂度分析

* 时间复杂度：$O(n^2)$。最坏的情况下，需要检查 $\frac{n(n+1)}{2}$ 对整数。因此，时间复杂度为 $O(n^2)$。
* 空间复杂度：$O(1)$。只使用了常数额外空间。

### 注意

本方法在 Leetcode 上会超时。一般而言，如果一个算法的时间复杂度为 $O(n^2)$，它最多能处理 $n$ 大约为 $10^4$ 的数据。当 $n$ 接近 $10^5$ 时就会超时。

## 方法二：排序 【通过】

### 直觉

如果存在重复元素，排序后它们应该相邻。

### 算法

本方法使用排序算法。由于比较排序算法，如**堆排序**，可以在最坏情况下具有 $O(n \log n)$ 的时间复杂度。因此，排序经常是很好的预处理方法。排序之后，我们可以扫描已排序的数组,以查找是否有任何连续的重复元素。

**Java:**

```java
public boolean containsDuplicate(int[] nums) {
    Arrays.sort(nums);
    for (int i = 0; i < nums.length - 1; ++i) {
        if (nums[i] == nums[i + 1]) return true;
    }
    return false;
}
```

### 复杂度分析

* 时间复杂度 : $O(n \log n)$。排序的复杂度是 $O(n \log n)$，扫描的复杂度是 $O(n)$。整个算法主要由排序过程决定，因此是 $O(n \log n)$。
* 空间复杂度 : $O(1)$。这取决于具体的排序算法实现，通常而言，使用 `堆排序` 的话，是 `O(1)`。

### 注意

此处的算法实现对原始数组进行排序，修改了原始数组。通常，除非调用方清楚输入数据将被修改，否则不应该随意修改输入数据。可以先复制 `nums`，然后对副本进行操作。

## 方法三：哈希表 【通过】

### 直觉

利用支持快速搜索和插入操作的动态数据结构。

### 算法

从方法一中我们知道，对无序数组的查找操作的时间复杂度为 $O(n)$，而我们会重复调用查找操作。因此，使用搜索时间更快的数据结构将加快整个算法的速度。

有许多数据结构常用作动态集合,如二进制搜索树和哈希表。这里我们需要的操作是 `search` 和 `insert`。对于平衡二叉搜索树（Java 中的 TreeSet 或 TreeMap），`search` 和 `insert` 的时间复杂度均为 $O(\log n)$。对于哈希表（Java 中的 HashSet 或 HashMap），`search` 和 `insert` 的平均时间复杂度为 $O(1)$。因此，通过使用哈希表，我们可以达到在线性时间复杂度解决问题。

**Java:**

```java
public boolean containsDuplicate(int[] nums) {
    Set<Integer> set = new HashSet<>(nums.length);
    for (int x: nums) {
        if (set.contains(x)) return true;
        set.add(x);
    }
    return false;
}
```

### 复杂度分析

* 时间复杂度：$O(n)$。`search()` 和 `insert()` 各自使用 $n$ 次，每个操作耗费常数时间。
* 空间复杂度：$O(n)$。哈希表占用的空间与元素数量是线性关系。

### 注意

对于一些特定的 $n$ 不太大的测试样例，本方法的运行速度可能会比方法二更慢。这是因为哈希表在维护其属性时有一些开销。要注意，程序的实际运行表现和 Big-O 符号表示可能有所不同。Big-O 只是告诉我们在 *充分* 大的输入下，算法的相对快慢。因此，在 $n$ 不够大的情况下，$O(n)$ 的算法也可以比 $O(n \log n)$ 的更慢。

***

# Solution

This article is for beginners. It introduces the following ideas: Loop Invariant, Linear Search, Sorting and Hash Table.

## Approach #1 (Naive Linear Search) [Time Limit Exceeded]

### Intuition

For an array of $n$ integers, there are $C(n, 2) = \frac{n(n+1)}{2}$ pairs of integers. Thus, we may check all $\frac{n(n+1)}{2}$ pairs and see if there is any pair with duplicates.

### Algorithm

To apply this idea, we employ the linear search algorithm which is the simplest search algorithm. Linear search is a method of finding if a particular value is in a list by checking each of its elements, one at a time and in sequence until the desired one is found.

For our problem, we loop through all $n$ integers. For the $i$th integer `nums[i]`, we search in the previous `i-1` integers for the duplicate of `nums[i]`. If we find one, we return true; if not, we continue. Return false at the end of the program.

To prove the correctness of the algorithm, we define the loop invariant. A loop invariant is a property that holds before (and after) each iteration. Knowing its invariant(s) is essential for understanding the effect of a loop. Here is the *loop invariant*:

> Before the next search, there are no duplicate integers in the searched integers.

The loop invariant holds true before the loop because there is no searched integer. Each time through the loop we look for any any possible duplicate of the current element. If we found a duplicate, the function exits by returning true; If not, the invariant still holds true.

Therefore, if the loop finishes, the invariant tells us that there is no duplicate in all $n$ integers.

**Java:**

```java
public boolean containsDuplicate(int[] nums) {
    for (int i = 0; i < nums.length; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[j] == nums[i]) return true;  
        }
    }
    return false;
}
// Time Limit Exceeded
```

### Complexity Analysis

* Time complexity: $O(n^2)$. In the worst case, there are $\frac{n(n+1)}{2}$ pairs of integers to check. Therefore, the time complexity is $O(n^2)$.
* Space complexity: $O(1)$. We only used constant extra space.

### Note

This approach will get Time Limit Exceeded on LeetCode. Usually, if an algorithm is $O(n^2)$, it can handle $n$ up to around $10^4$. It gets Time Limit Exceeded when $n\geq 10^5$.

## Approach #2 (Sorting) [Accepted]

### Intuition

If there are any duplicate integers, they will be consecutive after sorting.

### Algorithm

This approach employs sorting algorithm. Since comparison sorting algorithm like *heapsort* is known to provide $O(n \log n)$ worst-case performance, sorting is often a good preprocessing step. After sorting, we can sweep the sorted array to find if there are any two consecutive duplicate elements.

```java
public boolean containsDuplicate(int[] nums) {
    Arrays.sort(nums);
    for (int i = 0; i < nums.length - 1; ++i) {
        if (nums[i] == nums[i + 1]) return true;
    }
    return false;
}
```

### Complexity Analysis

* Time complexity: $O(n \log n)$. Sorting is $O(n \log n)$ and the sweeping is $O(n)$. The entire algorithm is dominated by the sorting step, which is $O(n \log n)$.
* Space complexity: $O(1)$. Space depends on the sorting implementation which, usually, costs $O(1)$ auxiliary space if `heapsort` is used.

### Note

The implementation here modifies the original array by sorting it. In general, it is not a good practice to modify the input unless it is clear to the caller that the input will be modified. One may make a copy of `nums` and operate on the copy instead.

## Approach #3 (Hash Table) [Accepted]

### Intuition

Utilize a dynamic data structure that supports fast search and insert operations.

### Algorithm

From Approach #1 we know that search operations is $O(n)$ in an unsorted array and we did so repeatedly. Utilizing a data structure with faster search time will speed up the entire algorithm.

There are many data structures commonly used as dynamic sets such as Binary Search Tree and Hash Table. The operations we need to support here are `search()` and `insert()`. For a self-balancing Binary Search Tree (TreeSet or TreeMap in Java), `search()` and `insert()` are both $O(\log n)$ time. For a Hash Table (HashSet or HashMap in Java), `search()` and `insert()` are both $O(1)$ on average. Therefore, by using hash table, we can achieve linear time complexity for finding the duplicate in an unsorted array.

**Java:**

```java
public boolean containsDuplicate(int[] nums) {
    Set<Integer> set = new HashSet<>(nums.length);
    for (int x: nums) {
        if (set.contains(x)) return true;
        set.add(x);
    }
    return false;
}
```

### Complexity Analysis

* Time complexity: $O(n)$. We do `search()` and `insert()` for $n$ times and each operation takes constant time.
* Space complexity: $O(n)$. The space used by a hash table is linear with the number of elements in it.

### Note

For certain test cases with not very large $n$, the runtime of this method can be slower than Approach #2. The reason is hash table has some overhead in maintaining its property. One should keep in mind that real world performance can be different from what the Big-O notation says. The Big-O notation only tells us that for *sufficiently* large input, one will be faster than the other. Therefore, when $n$ is not sufficiently large, an $O(n)$ algorithm can be slower than an $O(n \log n)$ algorithm.
