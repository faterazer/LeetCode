import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<String> summaryRanges(int[] nums) {
        List<String> ret = new ArrayList<>();
        for (int i = 0; i < nums.length;) {
            int j = i + 1;
            while (j < nums.length && nums[j] == nums[j - 1] + 1)
                j++;
            if (i != j - 1)
                ret.add(nums[i] + "->" + nums[j - 1]);
            else
                ret.add(nums[i] + "");
            i = j;
        }
        return ret;
    }
}
