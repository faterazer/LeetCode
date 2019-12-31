# 官方题解

## 方法 1：双指针

### 算法

我们可以使用 [两数之和](https://leetcode-cn.com/problems/two-sum/solution/liang-shu-zhi-he-by-leetcode-2/) 的解法在 $O(n^2)$ 时间 $O(1)$ 空间暴力解决，也可以用哈希表在 $O(n)$ 时间和 $O(n)$ 空间内解决。然而，这两种方法都没有用到输入数组已经排序的性质，我们可以做得更好。

我们使用两个指针，初始分别位于第一个元素和最后一个元素位置，比较这两个元素之和与目标值的大小。如果和等于目标值，我们发现了这个唯一解。如果比目标值小，我们将较小元素指针增加一。如果比目标值大，我们将较大指针减小一。移动指针后重复上述比较知道找到答案。

假设 $[\ldots,a,b,c,\ldots,d,e,f,\ldots]$ 是已经升序排列的输入数组，并且元素 $b$，$e$ 是唯一解。因为我们从左到右移动较小指针，从右到左移动较大指针，总有某个时刻存在一个指针移动到 $b$ 或 $e$ 的位置。不妨假设小指针县移动到了元素 $b$，这是两个元素的和一定比目标值大，根据我们的算法，我们会向左移动较大指针直至获得结果。

```Cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int low = 0, high = numbers.size() - 1;
        while (low < high) {
            int sum = numbers[low] + numbers[high];
            if (sum == target)
                return {low + 1, high + 1};
            else if (sum < target)
                ++low;
            else
                --high;
        }
        return {-1, -1};
    }
};
```

是否需要考虑 $numbers[low]+numbers[high]$ 溢出呢？答案是不需要。因为即使两个元素之和溢出了，因为只存在唯一解，所以一定会先访问到答案。

### 复杂度分析

* 时间复杂度：$O(n)$。每个元素最多被访问一次，共有 $n$ 个元素。
* 空间复杂度：$O(1)$。只是用了两个指针。
