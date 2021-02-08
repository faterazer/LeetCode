import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
    public int numPrimeArrangements(int n) {
        // 线性筛（欧拉筛），计算出给定范围内的素数个数
        boolean[] buff = new boolean[n + 1];
        Arrays.fill(buff, true);
        List<Integer> primes = new ArrayList<>();
        for (int i = 2; i <= n; i++) {
            if (buff[i]) {
                primes.add(i);
            }
            for (int j = 0; j < primes.size() && primes.get(j) * i <= n; j++) {
                buff[primes.get(j) * i] = false;
                if (i % primes.get(j) == 0)
                    break;
            }
        }
        int a = primes.size(), b = n - a;   // 给定范围内有 a 个素数，b 个合数，res = a! + b!
        final int MOD = 1000000007;
        long res = 1;
        for (int i = 2; i <= a; i++) {
            res = (res * i) % MOD;
        }
        for (int i = 2; i <= b; i++) {
            res = (res * i) % MOD;
        }
        return (int) res;
    }
}
