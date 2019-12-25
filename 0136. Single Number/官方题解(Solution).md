# 官方题解

## 方法 1：列表操作

### 算法

1. 遍历 `nums` 中的每一个元素
2. 如果某个 `nums` 中的数字是新出现的，则将它添加到列表中
3. 如果某个数字已经在列表中，删除它

Python:

```python
class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        no_duplicate_list = []
        for i in nums:
            if i not in no_duplicate_list:
                no_duplicate_list.append(i)
            else:
                no_duplicate_list.remove(i)
        return no_duplicate_list.pop()
```

### 复杂度分析

* 时间复杂度：$O(n^2)$。我们遍历 `nums` 花费 $O(n)$ 的时间。我们还要在列表中遍历判断是否存在这个数字，花费 $O(n)$ 的时间，所以总循环时间为 $O(n^2)$。
* 空间复杂度：$O(n)$。我们需要一个大小为 $n$ 的列表保存所有的 `nums` 中元素。

## 方法 2：哈希表

### 算法

我们用哈希表避免每次查找元素是否存在需要的 $O(n)$ 时间。

1. 遍历 `nums` 中的每一个元素
2. 查找 `hash_table` 中是否有当前元素的键
3. 如果没有，将当前元素作为键插入 `hash_table`
4. 最后，`hash_table` 中仅有一个元素，用 `popitem` 获得它

Python:

```python
class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        hash_table = {}
        for i in nums:
            try:
                hash_table.pop(i)
            except:
                hash_table[i] = 1
        return hash_table.popitem()[0]
```

### 复杂度分析

* 时间复杂度：$O(n \cdot 1) = O(n)$。`for` 循环的时间复杂度是 $O(n)$ 的。Python 中哈希表的 `pop` 操作时间复杂度为 $O(1)$。
* 空间复杂度：$O(n)$。`hash_table` 需要的空间与 `nums` 中元素个数相等。

## 方法 3：数学

### 概念

$$
2 \times (a+b+c) - (a+a+b+b+c) = c
$$

Python:

```python
class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return 2 * sum(set(nums)) - sum(nums)
```

### 复杂度分析

* 时间复杂度：$O(n+n)=O(n)$。`sum` 会调用 `next` 将 `nums` 中的元素遍历一遍。我们可以把上述代码看成 `sum(list(i, for i in nums))`，这意味着时间复杂度为 $O(n)$，因为 `nums` 中的元素个数是 $n$ 个。
* 空间复杂度：$O(n+n)=O(n)$。`set` 需要的空间跟 `nums` 中元素个数相等。

## 方法 4：位操作

### 概念

* 如果我们对 0 和二进制位做 XOR 运算，得到的仍然是这个二进制位
  * $a \oplus 0 = a$
* 如果我们对相同的二进制位做 XOR 运算，返回的结果是 0
  * $a \oplus a = 0$
* XOR 满足交换律和结合律
  * $a \oplus b \oplus a = (a \oplus a) \oplus b = 0 \oplus b = b$

所以我们只需要将所有的数进行 XOR 操作，得到那个唯一的数字。

Python:

```python
class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        a = 0
        for i in nums:
            a ^= i
        return a
```

### 复杂度分析

* 时间复杂度：$O(n)$。我们只需要将 `nums` 中的元素遍历一遍，所以时间复杂度就是 `nums` 中的元素个数。
* 空间复杂度：$O(1)$。

***

# Solution

## Approach 1: List operation

### Algorithm

1. Iterative over all the elements in `nums`
2. If some number in `nums` is new to array, append it
3. If some number is already in the array, remove it

Python:

```python
class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        no_duplicate_list = []
        for i in nums:
            if i not in no_duplicate_list:
                no_duplicate_list.append(i)
            else:
                no_duplicate_list.remove(i)
        return no_duplicate_list.pop()
```

### Complexity Analysis

* Time complexity: $O(n^2)$. We iterate through `nums`, taking $O(n)$ time. We search the whole list to find whether there is duplicate number, taking $O(n)$ time. Because search is in the `for` loop, so we have to multiply both time complexities which is $O(n^2)$.
* Space complexity: $O(n)$. We need a list of size $n$ to contain elements in `nums`.

## Approach 2: Hash Table

### Algorithm

We use hash table to avoid the $O(n)$ time required for searching the elements.

1. Iterate through all elements in `nums`
2. Try if `hash_table` has the key for `pop`
3. If not, set up key/value pair
4. In the end, there is only one element in `hash_table`, so use popitem to get it

Python:

```python
class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        hash_table = {}
        for i in nums:
            try:
                hash_table.pop(i)
            except:
                hash_table[i] = 1
        return hash_table.popitem()[0]
```

### Complexity Analysis

* Time complexity: $O(n \cdot 1) = O(n)$. Time complexity of `for` loop is $O(n)$. Time complexity of hash table (dictionary in python) operation `pop` is $O(1)$.
* Space complexity: $O(n)$. The space required by `hash_table` is equal to the number of elements in `nums`.

## Approach 3: Math

### Concept

$$
2 \times (a+b+c) - (a+a+b+b+c) = c
$$

Python:

```python
class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return 2 * sum(set(nums)) - sum(nums)
```

### Complexity Analysis

* Time complexity: $O(n+n)=O(n)$. `sum` will call `next` to iterate through `nums`. We can see it as `sum(list(i, for i in nums))` which means the time complexity is $O(n)$ because of the number of elements($n$) in `nums`.
* Space complexity: $O(n+n)=O(n)$. `set` needs space for the elements in `nums`.

## Approach 4: Bit Manipulation

### Concept

* If we take XOR of zero and some bit, it will return that bit
  * $a \oplus 0 = a$
* If we take XOR of two same bits, it will return 0
  * $a \oplus a = 0$
* $a \oplus b \oplus a = (a \oplus a) \oplus b = 0 \oplus b = b$

Python:

```python
class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        a = 0
        for i in nums:
            a ^= i
        return a
```

### Complexity Analysis

* Time complexity: $O(n)$. We only iterate through `nums`, so the time complexity is the number of elements in `nums`.
* Space complexity: $O(1)$.
