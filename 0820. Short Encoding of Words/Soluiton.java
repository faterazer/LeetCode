import java.util.*;

class TrieNode {
    Map<Character, TrieNode> children = new HashMap<>();
    int depth;
}

class Solution {
    public int minimumLengthEncoding(String[] words) {
        TrieNode root = new TrieNode();
        List<TrieNode> leaves = new ArrayList<>();
        for (String w : new HashSet<>(Arrays.asList(words))) {
            TrieNode cur = root;
            for (int i = w.length() - 1; i >= 0; --i) {
                char c = w.charAt(i);
                if (!cur.children.containsKey(c)) {
                    cur.children.put(c, new TrieNode());
                }
                cur = cur.children.get(c);
            }
            cur.depth = w.length();
            leaves.add(cur);
        }

        int res = 0;
        for (TrieNode leaf : leaves) {
            if (leaf.children.isEmpty()) {
                res += leaf.depth + 1;
            }
        }
        return res;
    }
}

