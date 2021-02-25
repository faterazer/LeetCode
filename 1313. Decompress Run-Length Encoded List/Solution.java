import java.util.Arrays;

class Solution {
    public int[] decompressRLElist(int[] nums) {
        int size = 0;
        for (int i = 0; i < nums.length; i += 2) {
            size += nums[i];
        }
        int[] ret = new int[size];
        int startIdx = 0;
        for (int i = 0; i < nums.length; i += 2) {
            Arrays.fill(ret, startIdx, startIdx + nums[i], nums[i + 1]);
            startIdx += nums[i];
        }
        return ret;
    }
}
