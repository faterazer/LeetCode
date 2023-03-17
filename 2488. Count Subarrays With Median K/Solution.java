class Solution {
    public int countSubarrays(int[] nums, int k) {
        int position = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == k) {
                position = i;
                break;
            }
        }

        Map<Integer, Integer> counter = new HashMap<>();
        counter.put(0, 1);
        for (int i = position - 1, balance = 0; i >= 0; i--) {
            balance += nums[i] < k ? 1 : -1;
            counter.put(balance, counter.getOrDefault(balance, 0) + 1);
        }
        int res = counter.get(0) + counter.getOrDefault(-1, 0);
        for (int i = position + 1, balance = 0; i < nums.length; i++) {
            balance += nums[i] > k ? 1 : -1;
            res += counter.getOrDefault(balance, 0) + counter.getOrDefault(balance - 1, 0);
        }
        return res;
    }
}
