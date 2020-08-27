import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<String> fizzBuzz(int n) {
        List<String> ret = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            StringBuilder s = new StringBuilder();
            if (i % 3 == 0)
                s.append("Fizz");
            if (i % 5 == 0)
                s.append("Buzz");
            if (s.length() == 0)
                s.append(i);
            ret.add(s.toString());
        }
        return ret;
    }
}
