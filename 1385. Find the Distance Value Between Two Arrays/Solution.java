import java.util.Arrays;

class Solution {
    private int lower_bound(int[] arr, int x) {
        int l = 0, r = arr.length - 1, m;
        while (l < r) {
            m = l + ((r - l) >> 1);
            if (arr[m] < x) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return l;
    }

    public int findTheDistanceValue(int[] arr1, int[] arr2, int d) {
        Arrays.sort(arr2);
        int res = 0;
        for (int x : arr1) {
            int i = lower_bound(arr2, x);
            if (i < arr2.length && Math.abs(x - arr2[i]) <= d || i > 0 && Math.abs(x - arr2[i - 1]) <= d) {
                continue;
            }
            res++;
        }
        return res;
    }
}
