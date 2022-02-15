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
