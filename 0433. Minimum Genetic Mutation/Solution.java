import java.util.LinkedList;
import java.util.Queue;

class Solution {
    private boolean isMutation(String old_s, String new_s) {
        int count = 0;
        for (int i = 0; i < old_s.length(); ++i) {
            count += old_s.charAt(i) != new_s.charAt(i) ? 1 : 0;
            if (count > 1) {
                return false;
            }
        }
        return count == 1;
    }

    public int minMutation(String start, String end, String[] bank) {
        boolean[] visited = new boolean[bank.length];
        Queue<String> queue = new LinkedList<>();
        queue.offer(start);
        int count = 0;
        while (!queue.isEmpty()) {
            ++count;
            int n = queue.size();
            for (int i = 0; i < n; i++) {
                String s = queue.remove();
                for (int j = 0; j < bank.length; j++) {
                    if (!visited[j] && isMutation(s, bank[j])) {
                        if (bank[j].equals(end)) {
                            return count;
                        } else {
                            visited[j] = true;
                            queue.offer(bank[j]);
                        }
                    }
                }
            }
        }
        return -1;
    }
}
