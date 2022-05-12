import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

class Solution {
    private boolean nextPermute(int[] nums) {
        int r = nums.length - 1;
        while (r > 0 && nums[r] < nums[r - 1]) {
            --r;
        }
        if (r == 0) {
            return false;
        }
        Arrays.sort(nums, r, nums.length);
        int idx = r - 1;
        while (nums[r] < nums[idx]) {
            ++r;
        }
        int temp = nums[idx];
        nums[idx] = nums[r];
        nums[r] = temp;
        return true;
    }

    public List<List<Integer>> permute(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> res = new ArrayList<>();
        do {
            res.add(Arrays.stream(nums).boxed().collect(Collectors.toList()));
        } while (nextPermute(nums));
        return res;
    }
}
