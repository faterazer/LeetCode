class Solution {
    public boolean checkPerfectNumber_MK1(int num) {
        if (num <= 1)
            return false;
        int sum = 1;
        for (int i = 2; i * i <= num; i++)
            if (num % i == 0)
                sum += i + num / i;
        return sum == num;
    }

    // Euclid-Euler Theorem
    public boolean checkPerfectNumber_MK2(int num) {
        int[] primes = {2, 3, 5, 7, 13};
        for (int prime : primes) {
            int t = Math.pow(2, prime - 1) * (Math.pow(2, prime) - 1);
            if (t == num)
                return true;
        }
        return false;
    }
}
