class Solution {
    public String toHex(int num) {
        String dec2hex = "0123456789abcdef";

        if (num == 0) {
            return "0";
        }
        StringBuilder sb = new StringBuilder();
        while (num != 0) {
            sb.append(dec2hex.charAt(num & 15));
            num >>>= 4;
        }
        return sb.reverse().toString();
    }
}
