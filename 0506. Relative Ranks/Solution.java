import java.util.Arrays;
import java.util.List;
import java.util.Map;

class Solution {
    public String[] findRelativeRanks(int[] nums) {
        int[] temp = nums.clone();
        for (int i = 0; i < nums.length; i++)
            temp[i] = nums[i];
        Arrays.sort(temp);
        Map<Integer, String> map = new HashMap<Integer, String>();
        for (int i = 0; i < temp.length; i++) {
            int t = temp[temp.length - i - 1];
            if (i == 0)
                map.put(t, "Gold Medal");
            else if (i == 1)
                map.put(t, "Silver Medal");
            else if (i == 2)
                map.put(t, "Bronze Medal");
            else
                map.put(t, String.valueOf(i + 1));
        }
        String[] ret = new String[nums.length];
        for (int i = 0; i < nums.length; i++)
            ret[i] = map.get(nums[i]);
        return ret;
    }
}