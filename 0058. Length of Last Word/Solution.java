class Solution {
    public int lengthOfLastWord(String s) {
        s = s.strip();
        return s.length() - s.lastIndexOf(" ") - 1;
    }
}
