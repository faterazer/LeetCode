import java.util.Arrays;

class Solution {
    public String[] reorderLogFiles(String[] logs) {
        int last = logs.length - 1;
        for (int i = last; i >= 0; i--) {
            int idx = logs[i].indexOf(' ') + 1;
            if (Character.isDigit(logs[i].charAt(idx))) {
                String tmp = logs[last];
                logs[last--] = logs[i];
                logs[i] = tmp;
            }
        }
        Arrays.sort(logs, 0, last + 1, (s1, s2) -> {
            int i = s1.indexOf(' ') + 1, j = s2.indexOf(' ') + 1;
            int r = s1.substring(i).compareTo(s2.substring(j));
            if (r != 0) {
                return r;
            } else {
                return s1.compareTo(s2);
            }
        });
        return logs;
    }
}
