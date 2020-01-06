# 官方题解

## 方法 1：暴力

### 想法

我们可以在平方级的时间里穷举所有情况，来检测每个数是不是众数。

### 算法

暴力算法遍历整个数组，然后用另一重循环统计每个数字出现的次数。将出现次数比其他数字加起来出现次数还多的元素返回。

Java:

```java
class Solution {
    public int majorityElement(int[] nums) {
        int majorityCount = nums.length/2;

        for (int num : nums) {
            int count = 0;
            for (int elem : nums) {
                if (elem == num) {
                    count += 1;
                }
            }

            if (count > majorityCount) {
                return num;
            }

        }

        return -1;
    }
}
```

Python:

```python
class Solution:
    def majorityElement(self, nums):
        majority_count = len(nums)//2
        for num in nums:
            count = sum(1 for elem in nums if elem == num)
            if count > majority_count:
                return num
```

### 复杂度分析

* 时间复杂度：$O(n^2)$

  暴力算法包含两重嵌套的 `for` 循环，每一层 $n$ 次迭代，所以总的是平方级的时间复杂度。

* 空间复杂度：$O(1)$

  暴力方法没有分配任何与输入规模成比例的额外的空间。

## 方法 2：哈希表

### 想法

我们知道出现次数最多的元素大于 $\lfloor \frac{n}{2} \rfloor$ 次，所以可以用哈希表来快速统计每个元素出现的次数。

### 算法

我们使用哈希表来存储每个元素，然后用一个循环在线性时间内遍历 `nums`，然后我们只需要返回有最大值的键。

Java:

```java
class Solution {
    private Map<Integer, Integer> countNums(int[] nums) {
        Map<Integer, Integer> counts = new HashMap<Integer, Integer>();
        for (int num : nums) {
            if (!counts.containsKey(num)) {
                counts.put(num, 1);
            }
            else {
                counts.put(num, counts.get(num)+1);
            }
        }
        return counts;
    }

    public int majorityElement(int[] nums) {
        Map<Integer, Integer> counts = countNums(nums);

        Map.Entry<Integer, Integer> majorityEntry = null;
        for (Map.Entry<Integer, Integer> entry : counts.entrySet()) {
            if (majorityEntry == null || entry.getValue() > majorityEntry.getValue()) {
                majorityEntry = entry;
            }
        }

        return majorityEntry.getKey();
    }
}
```

Python:

```python
class Solution:
    def majorityElement(self, nums):
        counts = collections.Counter(nums)
        return max(counts.keys(), key=counts.get)
```

### 复杂度分析

* 时间复杂度：$O(n)$

  我们将 `nums` 迭代一次，哈希表的插入是常数时间的。所以总时间复杂度为 $O(n)$ 时间的。

* 空间复杂度：$O(n)$

  哈希表最多包含 $n-\lfloor \frac{n}{2}\rfloor$ 个关系，所以占用的空间为 $O(n)$。这是因为任意一个长度为 $n$ 的数组最多只能包含 $n$ 个不同的值，但题中保证 `nums` 一定有一个众数，会占用（最少）$\lfloor \frac{n}{2} \rfloor + 1$ 个数字。因此最多有 $n-(\lfloor \frac{n}{2} \rfloor + 1)$ 个不同的其他数字，所以最多有 $n-\lfloor \frac{n}{2}\rfloor$ 个不同的元素。

## 方法 3：排序

### 想法

如果所有数字被单调递增或者单调递减的顺序排了序，那么众数的下标为 $\lfloor \frac{n}{2} \rfloor$（当 $n$ 是偶数时，下标为 $\lfloor \frac{n}{2} \rfloor + 1$）。

### 算法

对于这种算法，我们先将 nums 数组排序，然后返回上面所说的数字。下面解释了为什么这种策略是有效的。考虑下图（上面的例子是一个可能的奇数的情况，下面的例子是一个可能的偶数的情况）：

![排序](images/image1.png)

对于每种情况，数组下面的线表示如果众数是数组中最小值的情况下覆盖的下标。数组上面的线是数组中最大值的情况。其他情况，这条线会在这两种极端情况的中间。但我们看到即使是这两种极端情况，它们也会在下标为 $\lfloor \frac{n}{2} \rfloor$ 的地方有重叠。因此，无论众数是多少，返回 $\lfloor \frac{n}{2} \rfloor$ 下标对应的值都是正确的。

Java:

```java
class Solution {
    public int majorityElement(int[] nums) {
        Arrays.sort(nums);
        return nums[nums.length/2];
    }
}
```

Python:

```python
class Solution:
    def majorityElement(self, nums):
        nums.sort()
        return nums[len(nums)//2]
```

### 复杂度分析

* 时间复杂度：$O(n \lg n)$

  用 Python 和 Java 将数组排序开销都为 $O(n \lg n)$，它占据了运行的主要时间。

* 空间复杂度：$O(1)$ 或者 $O(n)$

  我们将 `nums` 就地排序，如果不能就地排序，我们必须使用线性空间将 `nums` 数组拷贝，然后再排序。

## 方法 4：随机化

### 想法

因为超过 $\lfloor \frac{n}{2} \rfloor$ 的数组下标被众数占据了，一个随机的下标很有可能存有众数。

### 算法

由于一个给定的下标对应的数字很有可能是众数，我们随机挑选一个下标，检查它的值是否是众数，如果是就返回，否则继续随机挑选。

Java:

```java
class Solution {
    private int randRange(Random rand, int min, int max) {
        return rand.nextInt(max - min) + min;
    }

    private int countOccurences(int[] nums, int num) {
        int count = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == num) {
                count++;
            }
        }
        return count;
    }

    public int majorityElement(int[] nums) {
        Random rand = new Random();

        int majorityCount = nums.length/2;

        while (true) {
            int candidate = nums[randRange(rand, 0, nums.length)];
            if (countOccurences(nums, candidate) > majorityCount) {
                return candidate;
            }
        }
    }
}
```

Python:

```python
import random

class Solution:
    def majorityElement(self, nums):
        majority_count = len(nums)//2
        while True:
            candidate = random.choice(nums)
            if sum(1 for elem in nums if elem == candidate) > majority_count:
                return candidate
```

### 复杂度分析

* 时间复杂度：$O(\infty)$

  理论上这个算法有可能跑无穷次（如果我们一直无法随机到众数），所以最坏时间复杂度是没有上限的。然而，运行的期望时间远小于无限次的 - 线性时间即可。为了更简单地分析，先说服你自己：由于众数占据 超过 数组一半的位置，期望的迭代次数会小于众数占据数组恰好一半的情况。因此，我们可以计算迭代的期望次数（下标为 prob 为原问题， mod 为众数恰好占据数组一半数目的问题）：

  $$
  \begin{aligned}
    EV({iters}_{prob}) &\leq EV({iters}_{mod}) \\[2ex]
    &= \lim_{n \to \infty} \sum_{i=1}^n i \cdot \frac{1}{2^i} \\[2ex]
    &= 2
    \end{aligned}
  $$

  因为级数会收敛，修改后问题的迭代期望次数是个常数。所以修改后问题的运行时间为线性的。因此，原问题期望运行时间也是线性的。

* 空间复杂度：$O(1)$

  就像暴力解，随机方法只需要常数级别的额外空间。

## 方法 5：分治

### 想法

如果我们知道数组左边一半和右边一半的众数，我们就可以用线性时间知道全局的众数是哪个。

### 算法

这里我们使用经典的分治算法递归求解，直到所有的子问题都是长度为 1 的数组。由于传输子数组需要额外的时间和空间，所以我们实际上只传输子区间的左右指针 `lo` 和 `hi` 表示相应区间的左右下标。长度为 1 的子数组中唯一的数显然是众数，直接返回即可。如果回溯后某区间的长度大于 1 ，我们必须将左右子区间的值合并。如果它们的众数相同，那么显然这一段区间的众数是它们相同的值。否则，我们需要比较两个众数在整个区间内出现的次数来决定该区间的众数。原问题的答案就是下标为 $0$ 和 $n$ 之间的众数这一子问题。

Java:

```java
class Solution {
    private int countInRange(int[] nums, int num, int lo, int hi) {
        int count = 0;
        for (int i = lo; i <= hi; i++) {
            if (nums[i] == num) {
                count++;
            }
        }
        return count;
    }

    private int majorityElementRec(int[] nums, int lo, int hi) {
        // base case; the only element in an array of size 1 is the majority
        // element.
        if (lo == hi) {
            return nums[lo];
        }

        // recurse on left and right halves of this slice.
        int mid = (hi-lo)/2 + lo;
        int left = majorityElementRec(nums, lo, mid);
        int right = majorityElementRec(nums, mid+1, hi);

        // if the two halves agree on the majority element, return it.
        if (left == right) {
            return left;
        }

        // otherwise, count each element and return the "winner".
        int leftCount = countInRange(nums, left, lo, hi);
        int rightCount = countInRange(nums, right, lo, hi);

        return leftCount > rightCount ? left : right;
    }

    public int majorityElement(int[] nums) {
        return majorityElementRec(nums, 0, nums.length-1);
    }
}
```

Python:

```python
class Solution:
    def majorityElement(self, nums, lo=0, hi=None):
        def majority_element_rec(lo, hi):
            # base case; the only element in an array of size 1 is the majority
            # element.
            if lo == hi:
                return nums[lo]

            # recurse on left and right halves of this slice.
            mid = (hi-lo)//2 + lo
            left = majority_element_rec(lo, mid)
            right = majority_element_rec(mid+1, hi)

            # if the two halves agree on the majority element, return it.
            if left == right:
                return left

            # otherwise, count each element and return the "winner".
            left_count = sum(1 for i in range(lo, hi+1) if nums[i] == left)
            right_count = sum(1 for i in range(lo, hi+1) if nums[i] == right)

            return left if left_count > right_count else right

        return majority_element_rec(0, len(nums)-1)
```

### 复杂度分析

* 时间复杂度：$O(n \lg n)$

  函数 `majority_element_rec` 会求解 2 个长度为 $\frac{n}{2}$ 的子问题，并做两遍长度为 $n$ 的线性扫描。因此，分治算法的时间复杂度可以表示为：

  $$
  T(n)=2T(\frac{n}{2})+2n
  $$

  根据[主定理](https://baike.baidu.com/item/%E4%B8%BB%E5%AE%9A%E7%90%86/3463232?fr=aladdin)，本题满足第二种情况，所以时间复杂度可以表示为：

  $$
  \begin{aligned}
  T(n) &= \Theta(n^{\log_ba} \log n) \\[2ex]
  &= \Theta(n^{\log_22} \log n) \\[2ex]
  &= \Theta(n \log n)
  \end{aligned}
  $$

* 空间复杂度：$O(\lg n)$

  尽管分治算法没有直接分配额外的数组空间，但因为递归的过程，在栈中使用了一些非常数的额外空间。因为算法每次将数组从每一层的中间断开，所以数组长度变为 1 之前只有 $O(\lg n)$ 次切断。由于递归树是平衡的，所以从根到每个叶子节点的长度都是 $O(\lg n)$。由于递归树是深度优先的，空间复杂度等于最长的一条路径，也就是 $O(\lg n)$。

## 方法 6：Boyer-Moore 投票算法

### 想法

如果我们把众数记为 $+1$，把其他数记为 $-1$，将它们全部加起来，显然和大于 0，从结果本身我们可以看出众数比其他数多。

### 算法

本质上， Boyer-Moore 算法就是找 `nums` 的一个后缀 $suf$，其中 $suf[0]$ 就是后缀中的众数。我们维护一个计数器，如果遇到一个我们目前的候选众数，就将计数器加一，否则减一。只要计数器等于 0，我们就将 `nums` 中之前访问的数字全部 *忘记*，并把下一个数字当做候选的众数。直观上这个算法不是特别明显为何是对的，我们先看下面这个例子（竖线用来划分每次计数器归零的情况）

[7, 7, 5, 7, 5, 1 | 5, 7 | 5, 5, 7, 7 | 7, 7, 7, 7]

首先，下标为 0 的 `7` 被当做众数的第一个候选。在下标为 5 处，计数器会变回 0。所以下标为 6 的 `5` 是下一个众数的候选者。由于这个例子中 `7` 是真正的众数，所以通过忽略掉前面的数字，我们忽略掉了同样多数目的众数和非众数。因此， `7` 仍然是剩下数字中的众数。

[7, 7, 5, 7, 5, 1 | 5, 7 | 5, 5, 7, 7 | 5, 5, 5, 5]

现在，众数是 `5` （在计数器归零的时候我们把候选从 `7` 变成了 `5`）。此时，我们的候选者并不是真正的众数，但是我们在 *遗忘* 前面的数字的时候，要去掉相同数目的众数和非众数（如果遗忘更多的非众数，会导致计数器变成负数）。

因此，上面的过程说明了我们可以放心地遗忘前面的数字，并继续求解剩下数字中的众数。最后，总有一个后缀满足计数器是大于 0 的，此时这个后缀的众数就是整个数组的众数。

Java:

```java
class Solution {
    public int majorityElement(int[] nums) {
        int count = 0;
        Integer candidate = null;

        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }

        return candidate;
    }
}
```

Python:

```python
class Solution:
    def majorityElement(self, nums):
        count = 0
        candidate = None

        for num in nums:
            if count == 0:
                candidate = num
            count += (1 if num == candidate else -1)

        return candidate
```

### 复杂度分析

* 时间复杂度：$O(n)$
  
  Boyer-Moore 算法严格执行了 $n$ 次循环，所以时间复杂度是线性时间的。

* 空间复杂度：$O(1)$

  Boyer-Moore 只需要常数级别的额外空间。

***

# Solution

## Approach 1: Brute Force

### Intuition

We can exhaust the search space in quadratic time by checking whether each element is the majority element.

### Algorithm

The brute force algorithm iterates over the array, and then iterates again for each number to count its occurrences. As soon as a number is found to have appeared more than any other can possibly have appeared, return it.

Java:

```java
class Solution {
    public int majorityElement(int[] nums) {
        int majorityCount = nums.length/2;

        for (int num : nums) {
            int count = 0;
            for (int elem : nums) {
                if (elem == num) {
                    count += 1;
                }
            }

            if (count > majorityCount) {
                return num;
            }

        }

        return -1;
    }
}
```

Python:

```python
class Solution:
    def majorityElement(self, nums):
        majority_count = len(nums)//2
        for num in nums:
            count = sum(1 for elem in nums if elem == num)
            if count > majority_count:
                return num
```

### Complexity Analysis

* Time complexity: $O(n^2)$

  The brute force algorithm contains two nested `for` loops that each run for $n$ iterations, adding up to quadratic time complexity.

* Space complexity: $O(1)$

  The brute force solution does not allocate additional space proportional to the input size.

## Approach 2: HashMap

### Intuition

We know that the majority element occurs more than $\lfloor \frac{n}{2} \rfloor$ times, and a `HashMap` allows us to count element occurrences efficiently.

### Algorithm

We can use a `HashMap` that maps elements to counts in order to count occurrences in linear time by looping over `nums`. Then, we simply return the key with maximum value.

Java:

```java
class Solution {
    private Map<Integer, Integer> countNums(int[] nums) {
        Map<Integer, Integer> counts = new HashMap<Integer, Integer>();
        for (int num : nums) {
            if (!counts.containsKey(num)) {
                counts.put(num, 1);
            }
            else {
                counts.put(num, counts.get(num)+1);
            }
        }
        return counts;
    }

    public int majorityElement(int[] nums) {
        Map<Integer, Integer> counts = countNums(nums);

        Map.Entry<Integer, Integer> majorityEntry = null;
        for (Map.Entry<Integer, Integer> entry : counts.entrySet()) {
            if (majorityEntry == null || entry.getValue() > majorityEntry.getValue()) {
                majorityEntry = entry;
            }
        }

        return majorityEntry.getKey();
    }
}
```

Python:

```python
class Solution:
    def majorityElement(self, nums):
        counts = collections.Counter(nums)
        return max(counts.keys(), key=counts.get)
```

### Complexity Analysis

* Time complexity: $O(n)$

  We iterate over `nums` once and make a constant time `HashMap` insertion on each iteration. Therefore, the algorithm runs in $O(n)$ time.

* Space complexity: $O(n)$

  At most, the `HashMap` can contain $n-\lfloor \frac{n}{2}\rfloor$ associations, so it occupies $O(n)$ space. This is because an arbitrary array of length $n$ can contain $n$ distinct values, but `nums` is guaranteed to contain a majority element, which will occupy (at minimum) $\lfloor \frac{n}{2} \rfloor + 1$ array indices. Therefore, $n-(\lfloor \frac{n}{2} \rfloor + 1)$ indices can be occupied by distinct, non-majority elements (plus 1 for the majority element itself), leaving us with (at most) $n-\lfloor \frac{n}{2}\rfloor$ distinct elements.

## Approach 3: Sorting

### Intuition

If the elements are sorted in monotonically increasing (or decreasing) order, the majority element can be found at index $\lfloor \frac{n}{2} \rfloor$ (and $\lfloor \frac{n}{2} \rfloor + 1$, incidentally, if $n$ is even).

### Algorithm

For this algorithm, we simply do exactly what is described: sort `nums`, and return the element in question. To see why this will always return the majority element (given that the array has one), consider the figure below (the top example is for an odd-length array and the bottom is for an even-length array):

![sorting](images/image1.png)

For each example, the line below the array denotes the range of indices that are covered by a majority element that happens to be the array minimum. As you might expect, the line above the array is similar, but for the case where the majority element is also the array maximum. In all other cases, this line will lie somewhere between these two, but notice that even in these two most extreme cases, they overlap at index $\lfloor \frac{n}{2} \rfloor$ for both even- and odd-length arrays. Therefore, no matter what value the majority element has in relation to the rest of the array, returning the value at $\lfloor \frac{n}{2} \rfloor$ will never be wrong.

Java:

```java
class Solution {
    public int majorityElement(int[] nums) {
        Arrays.sort(nums);
        return nums[nums.length/2];
    }
}
```

Python:

```python
class Solution:
    def majorityElement(self, nums):
        nums.sort()
        return nums[len(nums)//2]
```

### Complexity Analysis

* Time complexity: $O(n\lg n)$

  Sorting the array costs $O(n \lg n)$ time in Python and Java, so it dominates the overall runtime.

* Space complexity: $O(1)$ or $O(n)$

  We sorted `nums` in place here - if that is not allowed, then we must spend linear additional space on a copy of `nums` and sort the copy instead.

## Approach 4: Randomization

### Intuition

Because more than $\lfloor \frac{n}{2} \rfloor$ array indices are occupied by the majority element, a random array index is likely to contain the majority element.

### Algorithm

Because a given index is likely to have the majority element, we can just select a random index, check whether its value is the majority element, return if it is, and repeat if it is not. The algorithm is verifiably correct because we ensure that the randomly chosen value is the majority element before ever returning.

Java:

```java
class Solution {
    private int randRange(Random rand, int min, int max) {
        return rand.nextInt(max - min) + min;
    }

    private int countOccurences(int[] nums, int num) {
        int count = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == num) {
                count++;
            }
        }
        return count;
    }

    public int majorityElement(int[] nums) {
        Random rand = new Random();

        int majorityCount = nums.length/2;

        while (true) {
            int candidate = nums[randRange(rand, 0, nums.length)];
            if (countOccurences(nums, candidate) > majorityCount) {
                return candidate;
            }
        }
    }
}
```

Python:

```python
import random

class Solution:
    def majorityElement(self, nums):
        majority_count = len(nums)//2
        while True:
            candidate = random.choice(nums)
            if sum(1 for elem in nums if elem == candidate) > majority_count:
                return candidate
```

### Complexity Analysis

* Time complexity: $O(\infty)$

  It is technically possible for this algorithm to run indefinitely (if we never manage to randomly select the majority element), so the worst possible runtime is unbounded. However, the expected runtime is far better - linear, in fact. For ease of analysis, convince yourself that because the majority element is guaranteed to occupy *more* than half of the array, the expected number of iterations will be less than it would be if the element we sought occupied exactly *half* of the array. Therefore, we can calculate the expected number of iterations for this modified version of the problem and assert that our version is easier.

  $$
  \begin{aligned}
  EV({iters}_{prob}) &\leq EV({iters}_{mod}) \\[2ex]
  &= \lim_{n \to \infty} \sum_{i=1}^n i \cdot \frac{1}{2^i} \\[2ex]
  &= 2
  \end{aligned}
  $$

  Because the series converges, the expected number of iterations for the modified problem is constant. Based on an expected-constant number of iterations in which we perform linear work, the expected runtime is linear for the modifed problem. Therefore, the expected runtime for our problem is also linear, as the runtime of the modifed problem serves as an upper bound for it.

* Space complexity: $O(1)$

  Much like the brute force solution, the randomized approach runs with constant additional space.

## Approach 5: Divide and Conquer

### Intuition

If we know the majority element in the left and right halves of an array, we can determine which is the global majority element in linear time.

### Algorithm

Here, we apply a classical divide & conquer approach that recurses on the left and right halves of an array until an answer can be trivially achieved for a length-1 array. Note that because actually passing copies of subarrays costs time and space, we instead pass `lo` and `hi` indices that describe the relevant slice of the overall array. In this case, the majority element for a length-1 slice is trivially its only element, so the recursion stops there. If the current slice is longer than length-1, we must combine the answers for the slice's left and right halves. If they agree on the majority element, then the majority element for the overall slice is obviously the same. If they disagree, only one of them can be "right", so we need to count the occurrences of the left and right majority elements to determine which subslice's answer is globally correct. The overall answer for the array is thus the majority element between indices $0$ and $n$.

Java:

```java
class Solution {
    private int countInRange(int[] nums, int num, int lo, int hi) {
        int count = 0;
        for (int i = lo; i <= hi; i++) {
            if (nums[i] == num) {
                count++;
            }
        }
        return count;
    }

    private int majorityElementRec(int[] nums, int lo, int hi) {
        // base case; the only element in an array of size 1 is the majority
        // element.
        if (lo == hi) {
            return nums[lo];
        }

        // recurse on left and right halves of this slice.
        int mid = (hi-lo)/2 + lo;
        int left = majorityElementRec(nums, lo, mid);
        int right = majorityElementRec(nums, mid+1, hi);

        // if the two halves agree on the majority element, return it.
        if (left == right) {
            return left;
        }

        // otherwise, count each element and return the "winner".
        int leftCount = countInRange(nums, left, lo, hi);
        int rightCount = countInRange(nums, right, lo, hi);

        return leftCount > rightCount ? left : right;
    }

    public int majorityElement(int[] nums) {
        return majorityElementRec(nums, 0, nums.length-1);
    }
}
```

Python:

```python
class Solution:
    def majorityElement(self, nums, lo=0, hi=None):
        def majority_element_rec(lo, hi):
            # base case; the only element in an array of size 1 is the majority
            # element.
            if lo == hi:
                return nums[lo]

            # recurse on left and right halves of this slice.
            mid = (hi-lo)//2 + lo
            left = majority_element_rec(lo, mid)
            right = majority_element_rec(mid+1, hi)

            # if the two halves agree on the majority element, return it.
            if left == right:
                return left

            # otherwise, count each element and return the "winner".
            left_count = sum(1 for i in range(lo, hi+1) if nums[i] == left)
            right_count = sum(1 for i in range(lo, hi+1) if nums[i] == right)

            return left if left_count > right_count else right

        return majority_element_rec(0, len(nums)-1)
```

### Complexity Analysis

* Time complexity: $O(n \lg n)$

  Each recursive call to `majority_element_rec` performs two recursive calls on subslices of size $\frac{n}{2}$. Therefore, the time complexity of the divide & conquer approach can be represented by the following recurrence relation:

  $$
  T(n) = 2T(\frac{n}{2}) + 2n
  $$

  By the [master theorem](https://en.wikipedia.org/wiki/Master_theorem_(analysis_of_algorithms)), the recurrence satisfies case 2, so the complexity can be analyzed as such:

  $$
  \begin{aligned}
  T(n) &= \Theta(n^{\log_ba} \log n) \\[2ex]
  &= \Theta(n^{\log_22} \log n) \\[2ex]
  &= \Theta(n \log n)
  \end{aligned}
  $$

* Space complexity: $O(\lg n)$

  Although the divide & conquer does not explicitly allocate any additional memory, it uses a non-constant amount of additional memory in stack frames due to recursion. Because the algorithm "cuts" the array in half at each level of recursion, it follows that there can only be $O(\lg n)$ "cuts" before the base case of 1 is reached. It follows from this fact that the resulting recursion tree is balanced, and therefore all paths from the root to a leaf are of length $O(\lg n)$. Because the recursion tree is traversed in a depth-first manner, the space complexity is therefore equivalent to the length of the longest path, which is, of course, $O(\lg n)$.

## Approach 6: Boyer-Moore Voting Algorithm

### Intuition

If we had some way of counting instances of the majority element as $+1$ and instances of any other element as $-1$, summing them would make it obvious that the majority element is indeed the majority element.

### Algorithm

Essentially, what Boyer-Moore does is look for a suffix $suf$ of `nums` where $suf[0]$ is the majority element in that suffix. To do this, we maintain a count, which is incremented whenever we see an instance of our current candidate for majority element and decremented whenever we see anything else. Whenever `count` equals 0, we effectively forget about everything in `nums` up to the current index and consider the current number as the candidate for majority element. It is not immediately obvious why we can get away with forgetting prefixes of `nums` - consider the following examples (pipes are inserted to separate runs of nonzero `count`).

[7, 7, 5, 7, 5, 1 | 5, 7 | 5, 5, 7, 7 | 7, 7, 7, 7]

Here, the `7` at index 0 is selected to be the first candidate for majority element. `count` will eventually reach 0 after index 5 is processed, so the `5` at index 6 will be the next candidate. In this case, `7` is the true majority element, so by disregarding this prefix, we are ignoring an equal number of majority and minority elements - therefore, `7` will still be the majority element in the suffix formed by throwing away the first prefix.

[7, 7, 5, 7, 5, 1 | 5, 7 | 5, 5, 7, 7 | 5, 5, 5, 5]

Now, the majority element is `5` (we changed the last run of the array from `7`s to `5`s), but our first candidate is still `7`. In this case, our candidate is not the true majority element, but we still cannot discard more majority elements than minority elements (this would imply that `count` could reach -1 before we reassign `candidate`, which is obviously false).

Therefore, given that it is impossible (in both cases) to discard more majority elements than minority elements, we are safe in discarding the prefix and attempting to recursively solve the majority element problem for the suffix. Eventually, a suffix will be found for which `count` does not hit `0`, and the majority element of that suffix will necessarily be the same as the majority element of the overall array.

Java:

```java
class Solution {
    public int majorityElement(int[] nums) {
        int count = 0;
        Integer candidate = null;

        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }

        return candidate;
    }
}
```

Python:

```python
class Solution:
    def majorityElement(self, nums):
        count = 0
        candidate = None

        for num in nums:
            if count == 0:
                candidate = num
            count += (1 if num == candidate else -1)

        return candidate
```

### Complexity Analysis

* Time complexity: $O(n)$
  
  Boyer-Moore performs constant work exactly $n$ times, so the algorithm runs in linear time.

* Space complexity: $O(1)$
  
  Boyer-Moore allocates only constant additional memory.
