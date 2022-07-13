import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.List;

class Solution {
    public int[] asteroidCollision(int[] asteroids) {
        Deque<Integer> stack = new ArrayDeque<>();
        List<Integer> res = new ArrayList<>();
        for (int asteroid : asteroids) {
            if (asteroid > 0) {
                stack.addLast(asteroid);
                continue;
            }
            while (!stack.isEmpty() && stack.peekLast() + asteroid < 0) {
                stack.pollLast();
            }
            if (stack.isEmpty()) {
                res.add(asteroid);
            } else if (stack.peekLast() + asteroid == 0) {
                stack.pollLast();
            }
        }
        res.addAll(stack);
        return res.stream().mapToInt(e -> e).toArray();
    }
}
