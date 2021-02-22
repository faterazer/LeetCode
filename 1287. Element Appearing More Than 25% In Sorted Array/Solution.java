class Solution {
    public int findSpecialInteger(int[] arr) {
        int gap = arr.length / 4;
        for (int i = gap; i < arr.length; i += gap) {
            if (upper_bound(arr, arr[i]) - lower_bound(arr, arr[i]) > gap) {
                return arr[i];
            }
        }
        return 0;
    }

    private int lower_bound(int[] arr, int x) {
        int l = 0, r = arr.length;
        while (l < r) {
            int m = l + ((r - l) >> 1);
            if (arr[m] < x) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return l;
    }

    private int upper_bound(int[] arr, int x) {
        int l = 0, r = arr.length;
        while (l < r) {
            int m = l + ((r - l) >> 1);
            if (arr[m] > x) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return r;
    }
}
