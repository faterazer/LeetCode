import java.util.ArrayDeque;
import java.util.Deque;

class StockSpanner {
    private int count;
    private final Deque<int[]> stack = new ArrayDeque<>();

    public StockSpanner() {
        stack.push(new int[]{Integer.MAX_VALUE, 0});
        count = 1;
    }

    public int next(int price) {
        while (price >= stack.element()[0]) {
            stack.pop();
        }
        int res = count - stack.element()[1];
        stack.push(new int[]{price, count++});
        return res;
    }
}

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner obj = new StockSpanner();
 * int param_1 = obj.next(price);
 */
