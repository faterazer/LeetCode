import java.util.Arrays;

class Solution {
    public int minElements(int[] nums, int limit, int goal) {
        long sum = Arrays.stream(nums).mapToLong(x -> x).sum();
        long need = Math.abs(sum - goal);
        return Math.toIntExact((need + limit - 1) / limit);
    }
}
