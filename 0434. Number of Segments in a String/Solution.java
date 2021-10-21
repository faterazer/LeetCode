class Solution {
    public int countSegments(String s) {
        if (s.trim().isEmpty()) {
            return 0;
        }
        return s.trim().split("\\s+").length;
    }
}
