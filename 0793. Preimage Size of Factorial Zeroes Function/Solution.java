class Solution {
    private int numOfTrailingZeros(long x) {
        int res = 0;
        while (x > 0) {
            res += x / 5;
            x /= 5;
        }
        return res;
    }

    public int preimageSizeFZF(int k) {
        long left = 0, right = 5L * k;
        while (left <= right) {
            long mid = left + ((right - left) >> 1);
            int zeros = numOfTrailingZeros(mid);

            if (zeros == k) {
                return 5;
            } else if (zeros < k) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return 0;
    }
}
