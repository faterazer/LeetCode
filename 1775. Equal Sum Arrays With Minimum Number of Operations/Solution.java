import java.util.Arrays;

class Solution {
    private int helper(int[] cnt1, int[] cnt2, int diff) {
        int res = 0;
        for (int i = 1; i <= 6; i++) {
            while (cnt1[i]-- > 0) {
                res++;
                diff -= 6 - i;
                if (diff <= 0) {
                    return res;
                }
            }
            while (cnt2[7 - i]-- > 0) {
                res++;
                diff -= 6 - i;
                if (diff <= 0) {
                    return res;
                }
            }
        }
        return res;
    }

    public int minOperations(int[] nums1, int[] nums2) {
        int m = nums1.length, n = nums2.length;
        if (Math.max(m, n) > 6 * Math.min(m, n)) {
            return -1;
        }

        int sum1 = Arrays.stream(nums1).sum(), sum2 = Arrays.stream(nums2).sum();
        if (sum1 == sum2) {
            return 0;
        }

        int[] cnt1 = new int[7], cnt2 = new int[7];
        for (int x : nums1) {
            ++cnt1[x];
        }
        for (int x : nums2) {
            ++cnt2[x];
        }

        int diff = Math.abs(sum1 - sum2);
        if (sum1 < sum2) {
            return helper(cnt1, cnt2, diff);
        } else {
            return helper(cnt2, cnt1, diff);
        }
    }
}
