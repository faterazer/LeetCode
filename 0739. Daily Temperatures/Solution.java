import java.util.Deque;
import java.util.LinkedList;

class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        Deque<Integer> monoStack = new LinkedList<>();
        int[] res = new int[temperatures.length];
        for (int i = 0; i < temperatures.length; i++) {
            while (!monoStack.isEmpty() && temperatures[monoStack.peek()] < temperatures[i]) {
                int idx = monoStack.pop();
                res[idx] = i - idx;
            }
            monoStack.push(i);
        }
        return res;
    }
}
