import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
    public List<List<Integer>> minimumAbsDifference(int[] arr) {
        Arrays.sort(arr);
        List<List<Integer>> res = new ArrayList<>();
        int diff = Integer.MAX_VALUE;
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] - arr[i - 1] < diff) {
                diff = arr[i] - arr[i - 1];
                res.clear();
                res.add(List.of(arr[i - 1], arr[i]));
            } else if (arr[i] - arr[i - 1] == diff) {
                res.add(List.of(arr[i - 1], arr[i]));
            }
        }
        return res;
    }
}
