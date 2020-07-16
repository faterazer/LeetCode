class Solution {
    public String convertToBase7(int num) {
        boolean isNegative = num < 0;
        StringBuilder ret = new StringBuilder();
        do {
            ret.append(Integer.toString(Math.abs(num % 7)));
            num /= 7;
        } while(num != 0);
        if (isNegative)
            ret.append('-');
        ret = ret.reverse();
        return ret.toString();
    }
}
