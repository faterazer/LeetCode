class Solution {
    public int countGoodTriplets(int[] arr, int a, int b, int c) {
        int res = 0;
        int[] preSum = new int[1001];
        for (int j = 0; j < arr.length; j++) {
            for (int k = j + 1; k < arr.length; k++) {
                if (Math.abs(arr[j] - arr[k]) > b) continue;
                int l = Math.max(0, Math.max(arr[j] - a, arr[k] - c));
                int r = Math.min(1000, Math.min(arr[j] + a, arr[k] + c));
                if (l <= r) {
                    res += preSum[r];
                    if (l > 0) {
                        res -= preSum[l - 1];
                    }
                }
            }

            for (int k = arr[j]; k < 1001; k++) {
                preSum[k]++;
            }
        }
        return res;
    }
}
