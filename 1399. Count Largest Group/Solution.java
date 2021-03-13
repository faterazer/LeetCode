import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

class Solution {
    public int countLargestGroup(int n) {
        List<Integer> cnt = new ArrayList<>(Collections.nCopies(37, 0));
        for (int i = 1; i <= n; i++) {
            int sum = sumOfDigits(i);
            cnt.set(sum, cnt.get(sum) + 1);
        }
        return Collections.frequency(cnt, Collections.max(cnt));
    }

    private int sumOfDigits(int n) {
        int sum = 0;
        for (; n > 0; n /= 10) {
            sum += n % 10;
        }
        return sum;
    }
}
