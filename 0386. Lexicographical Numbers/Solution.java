import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<Integer> lexicalOrder(int n) {
        List<Integer> res = new ArrayList<>();
        int x = 1;
        for (int i = 1; i <= n; ++i) {
            res.add(x);
            x = nextNum(x, n);
        }
        return res;
    }

    private int nextNum(int x, int limit) {
        if (x * 10 <= limit) {
            return x * 10;
        } else {
            while (x + 1 > limit || x % 10 == 9) {
                x /= 10;
            }
            x += 1;
        }
        return x;
    }
}
