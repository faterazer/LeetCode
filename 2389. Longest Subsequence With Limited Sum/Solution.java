import java.util.Arrays;

class Solution {
    public int[] answerQueries(int[] nums, int[] queries) {
        Arrays.sort(nums);
        for (int i = 1; i < nums.length; i++) {
            nums[i] += nums[i - 1];
        }
        int[] res = new int[queries.length];
        for (int i = 0; i < res.length; i++) {
            res[i] = Math.abs(Arrays.binarySearch(nums, queries[i]) + 1);
        }
        return res;
    }
}
