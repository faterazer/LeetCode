class Solution {
    public boolean canTransform(String start, String end) {
        int n = start.length(), i = 0, j = 0;
        while (i < n && j < n) {
            while (i < n && start.charAt(i) == 'X') {
                ++i;
            }
            while (j < n && end.charAt(j) == 'X') {
                ++j;
            }
            if (i < n && j < n) {
                if (start.charAt(i) != end.charAt(j)) {
                    return false;
                }
                if (start.charAt(i) == 'L' && i < j) {
                    return false;
                }
                if (start.charAt(i) == 'R' && i > j) {
                    return false;
                }
                ++i;
                ++j;
            }
        }
        while (i < n) {
            if (start.charAt(i) != 'X') {
                return false;
            }
            ++i;
        }
        while (j < n) {
            if (end.charAt(j) != 'X') {
                return false;
            }
            ++j;
        }
        return true;
    }
}
