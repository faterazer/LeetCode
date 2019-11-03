# Solution

## Approach 1: Brute Force

The brute force approach is simple. Loop through each element $x$ and find if there is another value that equals to $target - x$.

```java
public int[] twoSum(int[] nums, int target) {
    for (int i = 0; i < nums.length; i++) {
        for (int j = i + 1; j < nums.length; j++) {
            if (nums[j] == target - nums[i]) {
                return new int[] { i, j };
            }
        }
    }
    throw new IllegalArgumentException("No two sum solution");
}
```

**Complexity Analysis:**

* Time complexity : $O(n^2)$. For each element, we try to find its complement by looping through the rest of array which takes $O(n)$ time. Therefore, the time complexity is $O(n^2)$.
* Space complexity : $O(1)$.

## Approach 2: Two-pass Hash Table

To improve our run time complexity, we need a more efficient way to check if the complement exists in the array. If the complement exists, we need to look up its index. What is the best way to maintain a mapping of each element in the array to its index? A hash table.

We reduce the look up time from $O(n)$ to $O(1)$ by trading space for speed. A hash table is built exactly for this purpose, it supports fast look up in *near* constant time. I say "near" because if a collision occurred, a look up could degenerate to $O(n)$ time. But look up in hash table should be amortized $O(1)$ time as long as the hash function was chosen carefully.

A simple implementation uses two iterations. In the first iteration, we add each element's value and its index to the table. Then, in the second iteration we check if each element's complement $(target - nums[i]) $ exists in the table. Beware that the complement must not be $nums[i]$ itself!

```java
public int[] twoSum(int[] nums, int target) {
    Map<Integer, Integer> map = new HashMap<>();
    for (int i = 0; i < nums.length; i++) {
        map.put(nums[i], i);
    }
    for (int i = 0; i < nums.length; i++) {
        int complement = target - nums[i];
        if (map.containsKey(complement) && map.get(complement) != i) {
            return new int[] { i, map.get(complement) };
        }
    }
    throw new IllegalArgumentException("No two sum solution");
}
```

**Complexity Analysis:**

* Time complexity : $O(n)$. We traverse the list containing $n$ elements exactly twice. Since the hash table reduces the look up time to $O(1)$, the time complexity is $O(n)$.
* Space complexity : $O(n)$. The extra space required depends on the number of items stored in the hash table, which stores exactly $n$ elements.

## Approach 3: One-pass Hash Table

It turns out we can do it in one-pass. While we iterate and inserting elements into the table, we also look back to check if current element's complement already exists in the table. If it exists, we have found a solution and return immediately.

```java
public int[] twoSum(int[] nums, int target) {
    Map<Integer, Integer> map = new HashMap<>();
    for (int i = 0; i < nums.length; i++) {
        int complement = target - nums[i];
        if (map.containsKey(complement)) {
            return new int[] { map.get(complement), i };
        }
        map.put(nums[i], i);
    }
    throw new IllegalArgumentException("No two sum solution");
}
```

**Complexity Analysis:**

* Time complexity : $O(n)$. We traverse the list containing nn elements only once. Each look up in the table costs only $O(1)$ time.
* Space complexity : $O(n)$. The extra space required depends on the number of items stored in the hash table, which stores at most $n$ elements.

***

# 解决方案

## 方法一：暴力法

暴力法很简单。遍历每个元素 $x$，并查找是否存在一个值与 $target - x$ 相等的目标元素。

```java
public int[] twoSum(int[] nums, int target) {
    for (int i = 0; i < nums.length; i++) {
        for (int j = i + 1; j < nums.length; j++) {
            if (nums[j] == target - nums[i]) {
                return new int[] { i, j };
            }
        }
    }
    throw new IllegalArgumentException("No two sum solution");
}
```

**复杂度分析：**

* 时间复杂度：$O(n^2)$， 对于每个元素，我们试图通过遍历数组的其余部分来寻找它所对应的目标元素，这将耗费 $O(n)$ 的时间。因此时间复杂度为 $O(n^2)$。
* 空间复杂度：$O(1)$。

## 方法二：两遍哈希表

为了对运行时间复杂度进行优化，我们需要一种更有效的方法来检查数组中是否存在目标元素。如果存在，我们需要找出它的索引。保持数组中的每个元素与其索引相互对应的最好方法是什么？哈希表。

通过以空间换取速度的方式，我们可以将查找时间从 $O(n)$ 降低到 $O(1)$。哈希表正是为此目的而构建的，它支持以 *近似* 恒定的时间进行快速查找。我用“近似”来描述，是因为一旦出现冲突，查找用时可能会退化到 $O(n)$。但只要你仔细地挑选哈希函数，在哈希表中进行查找的用时应当被摊销为 $O(1)$。

一个简单的实现使用了两次迭代。在第一次迭代中，我们将每个元素的值和它的索引添加到表中。然后，在第二次迭代中，我们将检查每个元素所对应的目标元素（$target - nums[i]$）是否存在于表中。注意，该目标元素不能是 $nums[i]$ 本身！

```java
public int[] twoSum(int[] nums, int target) {
    Map<Integer, Integer> map = new HashMap<>();
    for (int i = 0; i < nums.length; i++) {
        map.put(nums[i], i);
    }
    for (int i = 0; i < nums.length; i++) {
        int complement = target - nums[i];
        if (map.containsKey(complement) && map.get(complement) != i) {
            return new int[] { i, map.get(complement) };
        }
    }
    throw new IllegalArgumentException("No two sum solution");
}
```

**复杂度分析：**

* 时间复杂度：$O(n)$， 我们把包含有 $n$ 个元素的列表遍历两次。由于哈希表将查找时间缩短到 $O(1)$ ，所以时间复杂度为 $O(n)$。
* 空间复杂度：$O(n)$， 所需的额外空间取决于哈希表中存储的元素数量，该表中存储了 $n$ 个元素。

## 方法三：一遍哈希表

事实证明，我们可以一次完成。在进行迭代并将元素插入到表中的同时，我们还会回过头来检查表中是否已经存在当前元素所对应的目标元素。如果它存在，那我们已经找到了对应解，并立即将其返回。

```java
public int[] twoSum(int[] nums, int target) {
    Map<Integer, Integer> map = new HashMap<>();
    for (int i = 0; i < nums.length; i++) {
        int complement = target - nums[i];
        if (map.containsKey(complement)) {
            return new int[] { map.get(complement), i };
        }
        map.put(nums[i], i);
    }
    throw new IllegalArgumentException("No two sum solution");
}
```

**复杂度分析：**

* 时间复杂度：$O(n)$， 我们只遍历了包含有 $n$ 个元素的列表一次。在表中进行的每次查找只花费 $O(1)$ 的时间。
* 空间复杂度：$O(n)$， 所需的额外空间取决于哈希表中存储的元素数量，该表最多需要存储 $n$ 个元素。
