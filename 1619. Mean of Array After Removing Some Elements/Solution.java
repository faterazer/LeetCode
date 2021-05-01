import java.util.Arrays;

class Solution {
    public double trimMean_MK1(int[] arr) {
        int sum = 0, beg = arr.length / 20, end = arr.length - beg;
        Arrays.sort(arr);
        for (int i = beg; i < end; i++) {
            sum += arr[i];
        }
        return sum / (arr.length * 0.9);
    }

    public double trimMean_MK2(int[] arr) {
        int seg = arr.length / 20, sum = 0, end = arr.length - seg;
        kth_element(arr, 0, seg, arr.length - 1);
        kth_element(arr, seg, arr.length - seg, arr.length - 1);
        for (int i = seg; i < end; i++) {
            sum += arr[i];
        }
        return sum / (arr.length * 0.9);
    }

    private void kth_element(int arr[], int l, int k, int r) {
        if (l >= r || k < l || k > r) {
            return;
        }
        int last = l;
        for (int i = l + 1; i <= r; i++) {
            if (arr[i] <= arr[l]) {
                swap(arr, i, ++last);
            }
        }
        swap(arr, l, last);
        if (k < last) {
            kth_element(arr, l, k, last - 1);
        } else if (k > last) {
            kth_element(arr, last + 1, k, r);
        }
    }

    private void swap(int arr[], int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}
