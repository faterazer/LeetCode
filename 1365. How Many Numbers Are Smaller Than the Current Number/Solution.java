class Solution {
    public int[] smallerNumbersThanCurrent(int[] nums) {
        int map[] = new int[101];
        for (int num : nums)
            map[num]++;
        for (int i = 1; i < map.length; i++)
            map[i] += map[i - 1];
        int ret[] = new int[nums.length];
        for (int i = 0; i < nums.length; i++)
            if (nums[i] != 0)
                ret[i] = map[nums[i] - 1];
        return ret;
    }
}
