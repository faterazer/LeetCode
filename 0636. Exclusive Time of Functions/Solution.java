import java.util.ArrayDeque;
import java.util.Deque;
import java.util.List;

class Solution {
    public int[] exclusiveTime(int n, List<String> logs) {
        int[] res = new int[n];
        Deque<int[]> stack = new ArrayDeque<>();
        for (String log : logs) {
            String[] parts = log.split(":");
            int id = Integer.parseInt(parts[0]), timestamp = Integer.parseInt(parts[2]);
            if (parts[1].equals("start")) {
                if (!stack.isEmpty()) {
                    res[stack.getLast()[0]] += timestamp - stack.getLast()[1];
                }
                stack.addLast(new int[]{id, timestamp});
            } else {
                int[] p = stack.removeLast();
                res[p[0]] += timestamp - p[1] + 1;
                if (!stack.isEmpty()) {
                    stack.getLast()[1] = timestamp + 1;
                }
            }
        }
        return res;
    }
}
