import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;

class Solution {
    public List<String> letterCasePermutation(String s) {
        Queue<StringBuilder> queue = new ArrayDeque<>();
        queue.offer(new StringBuilder());
        for (int i = 0; i < s.length(); i++) {
            int size = queue.size();
            while (size-- != 0) {
                StringBuilder cur = queue.remove();
                if (Character.isLetter(s.charAt(i))) {
                    queue.offer(new StringBuilder(cur).append(Character.toLowerCase(s.charAt(i))));
                    cur.append(Character.toUpperCase(s.charAt(i)));
                    queue.offer(cur);
                } else {
                    cur.append(s.charAt(i));
                    queue.offer(cur);
                }
            }
        }
        List<String> res = new ArrayList<>();
        for (StringBuilder sb : queue) {
            res.add(sb.toString());
        }
        return res;
    }
}
