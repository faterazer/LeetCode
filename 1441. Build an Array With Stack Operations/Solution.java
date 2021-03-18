import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<String> buildArray(int[] target, int n) {
        List<String> res = new ArrayList<>();
        int i = 0;
        for (int x = 1; i != target.length; x++) {
            res.add("Push");
            if (x != target[i]) {
                res.add("Pop");
            } else {
                i++;
            }
        }
        return res;
    }
}
