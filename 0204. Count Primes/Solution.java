import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
    // 埃及筛
    public int countPrimes_MK1(int n) {
        int count = 0;
        boolean[] isPrims = new boolean[n];
        Arrays.fill(isPrims, true);
        for (int i = 2; i < n; i++) {
            if (isPrims[i]) {
                count++;
                if (i <= n / i) {
                    for (int j = i * i; j < n; j += i)
                        isPrims[j] = false;
                }
            }
        }
        return count;
    }

    // 欧拉筛(线性筛)
    public int countPrimes_MK2(int n) {
        boolean[] isPrims = new boolean[n];
        Arrays.fill(isPrims, true);
        List<Integer> primes = new ArrayList<>();
        for (int i = 2; i < n; i++) {
            if (isPrims[i])
                primes.add(i);
            for (int j = 0; j < primes.size() && i * primes.get(j) < n; j++) {
                isPrims[i * primes.get(j)] = false;
                if (i % primes.get(j) == 0)
                    break;
            }
        }
        return primes.size();
    }
}
