import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
    public List<List<Integer>> largeGroupPositions(String s) {
        List<List<Integer>> ret = new ArrayList<>();
        for (int i = 0, j = 0; j < s.length(); i = j) {
            while (j < s.length() && s.charAt(i) == s.charAt(j))
                j++;
            if (j - i >= 3)
                ret.add(Arrays.asList(i, j - 1));
        }
        return ret;
    }
}
