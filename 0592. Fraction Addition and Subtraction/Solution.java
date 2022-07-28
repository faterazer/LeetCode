import java.util.Scanner;

class Solution {
    public String fractionAddition(String expression) {
        Scanner scanner = new Scanner(expression).useDelimiter("/|(?=[-+])");
        int numerator1 = 0, denominator1 = 1;
        while (scanner.hasNext()) {
            int numerator2 = scanner.nextInt(), denominator2 = scanner.nextInt();
            numerator1 = numerator1 * denominator2 + numerator2 * denominator1;
            denominator1 *= denominator2;
            int g = gcd(numerator1, denominator1);
            numerator1 /= g;
            denominator1 /= g;
        }
        if (numerator1 == 0) {
            return "0/1";
        } else {
            return numerator1 + "/" + denominator1;
        }
    }

    private int gcd(int a, int b) {
        return b == 0 ? Math.abs(a) : gcd(b, a % b);
    }
}