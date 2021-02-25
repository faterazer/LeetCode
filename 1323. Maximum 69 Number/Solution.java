class Solution {
    public int maximum69Number_MK1(int num) {
        return Integer.parseInt(("" + num).replaceFirst("6", "9"));
    }

    public int maximum69Number_MK2(int num) {
        int i = 0;
        for (int n = num, j = 1; n > 0; n /= 10, j *= 10) {
            if (n % 10 == 6) {
                i = j;
            }
        }
        return num + 3 * i;
    }
}
