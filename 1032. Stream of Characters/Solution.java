import java.util.HashMap;
import java.util.Map;


class StreamChecker {
    class Trie {
        public Map<Character, Trie> children = new HashMap<>();
        public boolean isEnd = false;
    }

    private Trie root = new Trie();
    private StringBuilder charStream = new StringBuilder();

    private void update(String word) {
        Trie p = root;
        for (int i = word.length() - 1; i >= 0; i--) {
            if (!p.children.containsKey(word.charAt(i))) {
                p.children.put(word.charAt(i), new Trie());
            }
            p = p.children.get(word.charAt(i));
        }
        p.isEnd = true;
    }


    public StreamChecker(String[] words) {
        for (String word : words) {
            update(word);
        }
    }

    public boolean query(char letter) {
        charStream.append(letter);
        Trie p = root;
        for (int i = charStream.length() - 1; i >= 0 && p != null; i--) {
            char ch = charStream.charAt(i);
            p = p.children.getOrDefault(ch, null);
            if (p != null && p.isEnd) {
                return true;
            }
        }
        return false;
    }
}

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker obj = new StreamChecker(words);
 * boolean param_1 = obj.query(letter);
 */
