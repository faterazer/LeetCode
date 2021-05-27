class Solution {
    public boolean checkOnesSegment_MK1(String s) {
        return !s.contains("01");
    }

    public boolean checkOnesSegment_MK2(String s) {
        int count = 0;
        for (int i = 1; i < s.length(); i++) {
            if ((s.charAt(i) ^ s.charAt(i - 1)) == 1 && ++count > 1) {
                return false;
            }
        }
        return true;
    }
}
