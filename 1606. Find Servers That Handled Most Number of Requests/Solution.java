import java.util.*;

class Solution {
    public List<Integer> busiestServers(int k, int[] arrival, int[] load) {
        TreeSet<Integer> available = new TreeSet<>();
        for (int i = 0; i < k; ++i) {
            available.add(i);
        }
        PriorityQueue<int[]> busy = new PriorityQueue<>(Comparator.comparingInt(o -> o[0]));
        int[] serverCounter = new int[k];
        for (int i = 0; i < arrival.length; ++i) {
            while (!busy.isEmpty() && busy.peek()[0] <= arrival[i]) {
                available.add(busy.peek()[1]);
                busy.poll();
            }
            if (available.isEmpty()) {
                continue;
            }
            Integer server = available.ceiling(i % k);
            if (server == null) {
                server = available.first();
            }
            serverCounter[server] += 1;
            busy.add(new int[]{arrival[i] + load[i], server});
            available.remove(server);
        }
        int maxVal = Arrays.stream(serverCounter).max().getAsInt();
        List<Integer> res = new ArrayList<>();
        for (int i = 0; i < serverCounter.length; i++) {
            if (serverCounter[i] == maxVal) {
                res.add(i);
            }
        }
        return res;
    }
}
