#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    // Time complexity: O(n)
    // Space complexity: O(1)
    vector<int> findErrorNums_MK1(vector<int> &nums)
    {
        int dup = 0, sum = 0, n = nums.size();
        for (const int &num : nums) {
            if (nums[abs(num) - 1] < 0)
                dup = abs(num);
            else
                nums[abs(num) - 1] *= -1;
            sum += abs(num);
        }
        return vector<int>{dup, (((1 + n) * n) >> 1) - sum + dup};
    }

    // Time complexity: O(n)
    // Space complexity: O(1)
    // Note: (n * (n + 1) * (2 * n + 1) / 6 = 1^2 + 2^2 +...+ n^2
    vector<int> findErrorNums_MK2(vector<int> &nums)
    {
        long long sum = 0, sum2 = 0, n = nums.size();
        for (const int &num : nums) {
            sum += num;
            sum2 += num * num;
        }
        int a = (((1 + n) * n) >> 1) - sum;
        int b = ((n * (n + 1) * (2 * n + 1) / 6) - sum2) / a;
        return vector<int>{(b - a) >> 1, (b + a) >> 1};
    }

    // Time complexity: O(n)
    // Space complexity: O(1)
    // 位运算
    vector<int> findErrorNums_MK3(vector<int> &nums)
    {
        int x = 0, n = nums.size();
        for (const int &num : nums)
            x ^= num;
        for (int i = 1; i <= n; i++)
            x ^= i;
        int lowbit = x & (-x), a = 0, b = 0;
        for (const int &num : nums) {
            if (num & lowbit)
                a ^= num;
            else
                b ^= num;
        }
        for (int i = 1; i <= n; i++) {
            if (i & lowbit)
                a ^= i;
            else
                b ^= i;
        }
        for (const int &num : nums)
            if (a == num)
                return {a, b};
        return {b, a};
    }
};
