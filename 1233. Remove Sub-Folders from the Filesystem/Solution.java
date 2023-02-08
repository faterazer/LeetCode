import java.util.*;

class Solution {
    public List<String> removeSubfolders(String[] folder) {
        Set<String> seen = new HashSet<>();
        Arrays.sort(folder, Comparator.comparingInt(String::length));

        List<String> res = new ArrayList<>();
        for (String f : folder) {
            boolean check = true;
            for (int i = 2; i < f.length(); i++) {
                if (f.charAt(i) == '/' && seen.contains(f.substring(0, i))) {
                    check = false;
                    break;
                }
            }
            if (check) {
                res.add(f);
            }
            seen.add(f);
        }
        return res;
    }
}
