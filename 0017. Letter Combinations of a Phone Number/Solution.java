import java.util.LinkedList;
import java.util.List;

class Solution {
    public List<String> letterCombinations(String digits) {
        LinkedList<String> res = new LinkedList<>();
        if (digits.isEmpty()) {
            return res;
        }
        String[] table = new String[]{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        res.addLast("");
        for (int i = 0; i < digits.length(); ++i) {
            int n = res.size();
            for (int j = 0; j < n; ++j) {
                String s = res.removeFirst();
                for (char c : table[digits.charAt(i) - '0'].toCharArray()) {
                    res.addLast(s + c);
                }
            }
        }
        return res;
    }
}
