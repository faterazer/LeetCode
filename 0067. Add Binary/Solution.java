class Solution {
    public String addBinary(String a, String b) {
        int apos = a.length() - 1, bpos = b.length() - 1;
        int carry = 0;
        StringBuilder ret = new StringBuilder();
        while (apos >= 0 || bpos >= 0 || carry != 0) {
            if (apos >= 0)
                carry += a.charAt(apos--) - '0';
            if (bpos >= 0)
                carry += b.charAt(bpos--) - '0';
            ret.append((char)(carry % 2 + '0'));
            carry /= 2;
        }
        ret.reverse();
        return ret.toString();
    }
}
