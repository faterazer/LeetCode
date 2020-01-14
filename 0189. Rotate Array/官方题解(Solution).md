# 官方题解

## 方法 1：暴力

最简单的方法是旋转 $k$ 次，每次将数组旋转 $1$ 个元素。

Java:

```java
public class Solution {
    public void rotate(int[] nums, int k) {
        int temp, previous;
        for (int i = 0; i < k; i++) {
            previous = nums[nums.length - 1];
            for (int j = 0; j < nums.length; j++) {
                temp = nums[j];
                nums[j] = previous;
                previous = temp;
            }
        }
    }
}
```

### 复杂度分析

* 时间复杂度：$O(nk)$。每个元素都被移动 $1$ 步，移动 $k$ 次。
* 空间复杂度：$O(1)$。没有额外空间被使用。

## 方法 2：使用额外的数组

### 算法

我们可以用一个额外的数组来将每个元素放到正确的位置上，也就是原本数组里下标为 $i$ 的我们把它放到 $(i+k) \% \text{数组长度}$ 的位置。然后把新的数组拷贝到原数组中。

Java:

```java
public class Solution {
    public void rotate(int[] nums, int k) {
        int[] a = new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
            a[(i + k) % nums.length] = nums[i];
        }
        for (int i = 0; i < nums.length; i++) {
            nums[i] = a[i];
        }
    }
}
```

### 复杂度分析

* 时间复杂度：$O(n)$。将数字放到新的数组中需要一遍遍历，另一边来把新数组的元素拷贝回原数组。
* 空间复杂度：$O(n)$。另一个数组需要原数组长度的空间。

## 方法 3：使用环状替换

### 算法

如果我们直接把每一个数字放到它最后的位置，但这样的后果是遗失原来的元素。因此，我们需要把被替换的数字保存在变量 *temp* 里面。然后，我们将被替换数字（*temp*）放到它正确的位置，并继续这个过程 $n$ 次，$n$ 是数组的长度。这是因为我们需要将数组里所有的元素都移动。但是，这种方法可能会有个问题，如果 $n \% k == 0$，其中 $k = k \% n$（因为如果 $k$ 大于 $n$，移动 $k$ 次实际上相当于移动 $k \% n$ 次）。这种情况下，我们会发现在没有遍历所有数字的情况下回到出发数字。此时，我们应该从下一个数字开始再重复相同的过程。

现在，我们看看上面方法的证明。假设，数组里我们有 $n$ 个元素并且 $k$ 是要求移动的次数。更进一步，假设 $n \% k = 0$。第一轮中，所有移动数字的下标 $i$ 满足 $i \% k == 0$。这是因为我们没跳 $k$ 步，我们只会到达相距为 $k$ 个位置下标的数。每一轮，我们都会移动 $\frac{n}{k}$ 个元素。下一轮中，我们会移动满足 $i \% k == 1$ 的位置的数。这样的轮次会一直持续到我们再次遇到 $i \% k == 0$ 的地方为止，此时 $i=k$。此时在正确位置上的数字共有 $k \times \frac{n}{k} = n$ 个。因此所有数字都在正确位置上。

让我们看一下接下来的例子，以更好地说明这个过程：

```()
nums: [1, 2, 3, 4, 5, 6]
k: 2
```

![旋转数组](images/image1.png)

Java:

```java
public class Solution {
    public void rotate(int[] nums, int k) {
        k = k % nums.length;
        int count = 0;
        for (int start = 0; count < nums.length; start++) {
            int current = start;
            int prev = nums[start];
            do {
                int next = (current + k) % nums.length;
                int temp = nums[next];
                nums[next] = prev;
                prev = temp;
                current = next;
                count++;
            } while (start != current);
        }
    }
}
```

### 复杂度分析

* 时间复杂度：$O(n)$。只遍历了每个元素一次。
* 空间复杂度：$O(1)$。使用了常数个额外空间。

## 方法 4：使用反转

### 算法

这个方法基于这个事实：当我们旋转数组 $k$ 次，$k\%n$ 个尾部元素会被移动到头部，剩下的元素会被向后移动。

在这个方法中，我们首先将所有元素反转。然后反转前 $k$ 个元素，再反转后面 $n-k$ 个元素，就能得到想要的结果。

假设 $n=7$ 且 $k=3$。

```()
原始数组                  : 1 2 3 4 5 6 7
反转所有数字后             : 7 6 5 4 3 2 1
反转前 k 个数字后          : 5 6 7 4 3 2 1
反转后 n-k 个数字后        : 5 6 7 1 2 3 4 --> 结果
```

Java:

```java
public class Solution {
    public void rotate(int[] nums, int k) {
        k %= nums.length;
        reverse(nums, 0, nums.length - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.length - 1);
    }
    public void reverse(int[] nums, int start, int end) {
        while (start < end) {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
    }
}
```

### 复杂度分析

* 时间复杂度：$O(n)$。$n$ 个元素被反转了总共 $3$ 次。
* 空间复杂度：$O(1)$。没有使用额外的空间。

***

# Solution

## Approach 1 Brute Force [Time Limit Exceeded]

The simplest approach is to rotate all the elements of the array in k steps by rotating the elements by 1 unit in each step.

Java:

```java
public class Solution {
    public void rotate(int[] nums, int k) {
        int temp, previous;
        for (int i = 0; i < k; i++) {
            previous = nums[nums.length - 1];
            for (int j = 0; j < nums.length; j++) {
                temp = nums[j];
                nums[j] = previous;
                previous = temp;
            }
        }
    }
}
```

### Complexity Analysis

* Time complexity: $O(nk)$. All the numbers are shifted by one step ($O(n)$) k times ($O(k)$).
* Space complexity: $O(1)$. No extra space is used.

## Approach 2 Using Extra Array [Accepted]

### Algorithm

We use an extra array in which we place every element of the array at its correct position i.e. the number at index $i$ in the original array is placed at the index $(i+k)$. Then, we copy the new array to the original one.

Java:

```java
public class Solution {
    public void rotate(int[] nums, int k) {
        int[] a = new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
            a[(i + k) % nums.length] = nums[i];
        }
        for (int i = 0; i < nums.length; i++) {
            nums[i] = a[i];
        }
    }
}
```

### Complexity Analysis

* Time complexity: $O(n)$. One pass is used to put the numbers in the new array. And another pass to copy the new array to the original one.
* Space complexity: $O(n)$. Another array of the same size is used.

## Approach 3 Using Cyclic Replacements [Accepted]

### Algorithm

We can directly place every number of the array at its required correct position. But if we do that, we will destroy the original element. Thus, we need to store the number being replaced in a *temp* variable. Then, we can place the replaced number(*temp*) at its correct position and so on, $n$ times, where $n$ is the length of array. We have chosen $n$ to be the number of replacements since we have to shift all the elements of the array(which is $n$). But, there could be a problem with this method, if `n % k == 0` where `k = k % n` (since a value of $k$ larger than $n$ eventually leads to a $k \bmod n$ equivalent to $k$). In this case, while picking up numbers to be placed at the correct position, we will eventually reach the number from which we originally started. Thus, in such a case, when we hit the original number's index again, we start the same process with the number following it.

Now let's look at the proof of how the above method works. Suppose, we have $n$ as the number of elements in the array and $k$ is the number of shifts required. Further, assume $n$. Now, when we start placing the elements at their correct position, in the first cycle all the numbers with their index $i$ satisfying $i$ get placed at their required position. This happens because when we jump $k$ steps every time, we will only hit the numbers $k$ steps apart. We start with index $i=0$, having $i$. Thus, we hit all the numbers satisfying the above condition in the first cycle. When we reach back the original index, we have placed $\frac{n}{k}$ elements at their correct position, since we hit only that many elements in the first cycle. Now, we increment the index for replacing the numbers. This time, we place other $\frac{n}{k}$ elements at their correct position, different from the ones placed correctly in the first cycle, because this time we hit all the numbers satisfy the condition $i$. When we hit the starting number again, we increment the index and repeat the same process from $i=1$ for all the indices satisfying $i$. This happens till we reach the number with the index $i$ again, which occurs for $i=k$. We will reach such a number after a total of $k$ cycles. Now, the total count of numbers exclusive numbers placed at their correct position will be $k \times \frac{n}{k} = n$. Thus, all the numbers will be placed at their correct position.

Look at the following example to clarify the process: `nums: [1, 2, 3, 4, 5, 6] k: 2`

![rotate array](images/image1.png)

Java:

```java
public class Solution {
    public void rotate(int[] nums, int k) {
        k = k % nums.length;
        int count = 0;
        for (int start = 0; count < nums.length; start++) {
            int current = start;
            int prev = nums[start];
            do {
                int next = (current + k) % nums.length;
                int temp = nums[next];
                nums[next] = prev;
                prev = temp;
                current = next;
                count++;
            } while (start != current);
        }
    }
}
```

### Complexity Analysis

* Time complexity: $O(n)$. Only one pass is used.
* Space complexity: $O(1)$. Constant extra space is used.

## Approach 4 Using Reverse [Accepted]

### Algorithm

This approach is based on the fact that when we rotate the array $k$ time, $k$ elements from the back end of the array come to the front and the rest of the elements from the front shift backwards.

In this approach, we firstly reverse all the elements of the array. Then, reversing the first $k$ elements followed by reversing the rest $n-k$ elements gives us the required result.

Let $n=7$ and $k=3$.

```()
Original List                    : 1 2 3 4 5 6 7
After reversing all numbers      : 7 6 5 4 3 2 1
After reversing first k numbers  : 5 6 7 4 3 2 1
After reversing last n-k numbers : 5 6 7 1 2 3 4 --> Result
```

Java:

```java
public class Solution {
    public void rotate(int[] nums, int k) {
        k %= nums.length;
        reverse(nums, 0, nums.length - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.length - 1);
    }
    public void reverse(int[] nums, int start, int end) {
        while (start < end) {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
    }
}
```

### Complexity Analysis

* Time complexity: $O(n)$. $n$ elements are reversed a total of three times.
* Space complexity: $O(1)$. No extra space is used.
