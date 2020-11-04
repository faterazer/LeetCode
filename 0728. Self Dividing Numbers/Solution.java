import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<Integer> selfDividingNumbers(int left, int right) {
        List<Integer> ret = new ArrayList<>();
        for (int i = left; i <= right; i++)
            if (isSelfDividing(i))
                ret.add(i);
        return ret;
    }

    private boolean isSelfDividing(int n) {
        int digit;
        for (int i = n; i != 0; i /= 10) {
            digit = i % 10;
            if (digit == 0 || n % digit != 0)
                return false;
        }
        return true;
    }
}
