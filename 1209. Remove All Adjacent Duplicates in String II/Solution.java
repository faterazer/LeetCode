import java.util.ArrayDeque;
import java.util.Deque;

class Solution {
    public String removeDuplicates(String s, int k) {
        Deque<Character> charStack = new ArrayDeque<>();
        Deque<Integer> countStack = new ArrayDeque<>();
        for (int i = 0; i < s.length(); ++i) {
            if (charStack.isEmpty() || charStack.getLast() != s.charAt(i)) {
                charStack.addLast(s.charAt(i));
                countStack.addLast(1);
            } else {
                countStack.addLast(countStack.removeLast() + 1);
            }
            if (countStack.getLast() == k) {
                charStack.removeLast();
                countStack.removeLast();
            }
        }
        StringBuilder sb = new StringBuilder();
        while (!charStack.isEmpty()) {
            char c = charStack.removeFirst();
            int n = countStack.removeFirst();
            for (int i = 0; i < n; ++i) {
                sb.append(c);
            }
        }
        return sb.toString();
    }
}
