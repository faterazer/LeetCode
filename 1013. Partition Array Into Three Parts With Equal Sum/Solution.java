import java.util.Arrays;

class Solution {
    public boolean canThreePartsEqualSum(int[] arr) {
        int total = Arrays.stream(arr).sum();
        if (total % 3 != 0) return false;
        int sum = 0, target = total / 3, count = 0;
        int limit = target == 0 ? 3 : 2;
        for (int i = 0; i < arr.length && count < limit; i++) {
            sum += arr[i];
            if (sum == target) {
                sum = 0;
                count++;
            }
        }
        return count == limit;
    }
}
