import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.List;

class Solution {
    public boolean find132pattern_MK1(int[] nums) {
        /*
        Time complexity: O(nlgn)
        Space complexity: O(n)
        */
        Deque<Integer> stack = new ArrayDeque<>();
        stack.push(nums[nums.length - 1]);
        int maxK = Integer.MIN_VALUE;
        for (int i = nums.length - 2; i >= 0; --i) {
            if (nums[i] < maxK) {
                return true;
            }
            while (!stack.isEmpty() && nums[i] > stack.peek()) {
                maxK = stack.pop();
            }
            stack.push(nums[i]);
        }
        return false;
    }

    public boolean find132pattern_MK2(int[] nums) {
        /*
        Time complexity: O(nlgn)
        Space complexity: O(n)
        */
        Deque<Integer> stack = new ArrayDeque<>();
        List<Integer> preMin = new ArrayList<>();
        preMin.add(Integer.MAX_VALUE);
        for (int i = 0; i < nums.length; i++) {
            while (!stack.isEmpty() && nums[stack.peek()] <= nums[i]) {
                stack.pop();
            }
            if (!stack.isEmpty() && preMin.get(stack.peek()) < nums[i]) {
                return true;
            }
            stack.push(i);
            preMin.add(Math.min(preMin.get(preMin.size() - 1), nums[i]));
        }
        return false;
    }
}
