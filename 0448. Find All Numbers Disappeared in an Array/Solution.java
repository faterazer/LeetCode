import java.util.List;

class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        for (int n : nums)
            if (nums[Math.abs(n) - 1] > 0)
                nums[Math.abs(n) - 1] *= -1;
        List<Integer> ret = new ArrayList<Integer>();
        for (int i = 0; i < nums.length; i++)
            if (nums[i] > 0)
                ret.add(i + 1);
        return ret;
    }
}
