import java.util.Arrays;

class Solution {
    public String orderlyQueue(String s, int k) {
        char[] arr = s.toCharArray();
        if (k > 1) {
            Arrays.sort(arr);
            return new String(arr);
        } else {
            int n = s.length(), offset = 0, i = 0, j = 1;
            while (offset < n && i < n && j < n) {
                if (arr[(i + offset) % n] == arr[(j + offset) % n]) {
                    ++offset;
                } else {
                    if (arr[(i + offset) % n] > arr[(j + offset) % n]) {
                        i = i + offset + 1;
                    } else {
                        j = j + offset + 1;
                    }
                    if (i == j) {
                        ++i;
                    }
                    offset = 0;
                }
            }
            i = Math.min(i, j);
            return s.substring(i) + s.substring(0, i);
        }
    }
}
