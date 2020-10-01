import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.PriorityQueue;

class Solution {
    /**
     * Time complexity: O(nlgn).
     * Space complexity: O(1);
     */
    public int maximumProduct_MK1(int[] nums) {
        Arrays.sort(nums);
        return Math.max(nums[0] * nums[1] * nums[nums.length - 1], nums[nums.length - 1] * nums[nums.length - 2] * nums[nums.length - 3]);
    }

    /**
     * Time complexity: O(n)
     * Space complexity: O(1)
     */
    public int maximumProduct_MK2(int[] nums) {
        PriorityQueue<Integer> maxQueue = new PriorityQueue<>();
        PriorityQueue<Integer> minQueue = new PriorityQueue<>(Collections.reverseOrder());
        for (int num : nums) {
            maxQueue.offer(num);
            if (maxQueue.size() > 3)
                maxQueue.poll();
            minQueue.offer(num);
            if (minQueue.size() > 2)
                minQueue.poll();
        }
        int max1 = 1, max2 = 1;
        while (!maxQueue.isEmpty()) {
            max2 = maxQueue.poll();
            max1 *= max2;
        }
        while (!minQueue.isEmpty())
            max2 *= minQueue.poll();
        return Math.max(max1, max2);
    }
}
