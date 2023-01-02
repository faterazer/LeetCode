import java.util.Comparator;
import java.util.PriorityQueue;

class Solution {
    private final PriorityQueue<int[]> buyOrders = new PriorityQueue<>((a, b) -> b[0] - a[0]);
    private final PriorityQueue<int[]> sellOrders = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));

    public void buy(int[] order) {
        while (!sellOrders.isEmpty() && sellOrders.peek()[0] <= order[0]) {
            int[] o = sellOrders.poll();
            if (o[1] <= order[1]) {
                order[1] -= o[1];
            } else {
                o[1] -= order[1];
                order[1] = 0;
                sellOrders.offer(o);
                break;
            }
        }
        if (order[1] != 0) {
            buyOrders.offer(order);
        }
    }

    public void sell(int[] order) {
        while (!buyOrders.isEmpty() && buyOrders.peek()[0] >= order[0]) {
            int[] o = buyOrders.poll();
            if (o[1] <= order[1]) {
                order[1] -= o[1];
            } else {
                o[1] -= order[1];
                order[1] = 0;
                buyOrders.offer(o);
                break;
            }
        }
        if (order[1] != 0) {
            sellOrders.offer(order);
        }
    }

    public int getNumberOfBacklogOrders(int[][] orders) {
        for (int[] order : orders) {
            if (order[2] == 0) {
                buy(new int[]{order[0], order[1]});
            } else {
                sell(new int[]{order[0], order[1]});
            }
        }

        int P = 1000000007, res = 0;
        while (!buyOrders.isEmpty()) {
            res = (res + buyOrders.poll()[1]) % P;
        }
        while (!sellOrders.isEmpty()) {
            res = (res + sellOrders.poll()[1]) % P;
        }
        return res;
    }
}
