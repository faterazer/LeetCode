import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<Boolean> prefixesDivBy5(int[] A) {
        List<Boolean> ret = new ArrayList<>();
        int n = 0;
        for (int x : A) {
            n = (n * 2 + x) % 5;
            ret.add(n == 0);
        }
        return ret;
    }
}
