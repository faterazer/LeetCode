class Solution {
    public String thousandSeparator(int n) {
        StringBuilder sb = new StringBuilder();
        int count = 0;
        do {
            if (++count == 4) {
                sb.append('.');
                count = 1;
            }
            sb.append(n % 10);
            n /= 10;
        } while (n != 0);
        sb.reverse();
        return sb.toString();
    }
}
