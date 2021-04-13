import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<Integer> mostVisited(int n, int[] rounds) {
        List<Integer> res = new ArrayList<>();
        int bg = rounds[0], ed = rounds[rounds.length - 1];
        if (bg <= ed) {
            for (int i = bg; i <= ed; i++) {
                res.add(i);
            }
        } else {
            for (int i = 1; i <= ed; i++) {
                res.add(i);
            }
            for (int i = bg; i <= n; i++) {
                res.add(i);
            }
        }
        return res;
    }
}
