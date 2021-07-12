class Solution {
    /**
     * Time complexity: O(n).
     * Space complexity: O(1).
     */
    public int[] findErrorNums_MK1(int[] nums) {
        int sum = 0, dup = 0, n = nums.length;
        for (int num : nums) {
            if (nums[Math.abs(num) - 1] < 0)
                dup = Math.abs(num);
            else
                nums[Math.abs(num) - 1] *= -1;
            sum += Math.abs(num);
        }
        return new int[]{dup, (1 + n) * n / 2 - sum + dup};
    }

    /**
     * Time complexity: O(n)
     * Space complexity: O(1)
     * Note: (n * (n + 1) * (2 * n + 1) / 6 = 1^2 + 2^2 +...+ n^2
     */
    public int[] findErrorNums_MK2(int[] nums) {
        long sum = 0, sum2 = 0, n = nums.length;
        for (int num : nums) {
            sum += num;
            sum2 += (long) num * num;
        }
        int eq1 = (int) ((1 + n) * n / 2 - sum);
        int eq2 = (int) ((n * (n + 1) * (2 * n + 1) / 6 - sum2) / eq1);
        return new int[]{(eq2 - eq1) / 2, (eq1 + eq2) / 2};
    }

    /**
     * Time complexity: O(n)
     * Space complexity: O(1)
     * 位运算
     */
    public int[] findErrorNums_MK3(int[] nums) {
        int xor = 0;
        for (int num : nums) {
            xor ^= num;
        }
        for (int i = 1; i <= nums.length; i++) {
            xor ^= i;
        }
        int lowbit = xor & (-xor);
        int n1 = 0, n2 = 0;
        for (int num : nums) {
            if ((num & lowbit) != 0) {
                n1 ^= num;
            } else {
                n2 ^= num;
            }
        }
        for (int i = 1; i <= nums.length; i++) {
            if ((i & lowbit) != 0) {
                n1 ^= i;
            } else {
                n2 ^= i;
            }
        }
        for (int num : nums) {
            if (n1 == num) {
                return new int[]{n1, n2};
            } else if (n2 == num) {
                return new int[]{n2, n1};
            }
        }
        return new int[]{};
    }
}
