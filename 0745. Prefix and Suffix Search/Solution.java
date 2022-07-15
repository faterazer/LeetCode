import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

class TrieNode {
    public TrieNode[] children = new TrieNode[26];
    Set<Integer> set = new HashSet<>();
}

class WordFilter {
    private final TrieNode frontRoot = new TrieNode();
    private final TrieNode backRoot = new TrieNode();

    public WordFilter(String[] words) {
        Map<String, Integer> s2idx = new HashMap<>();
        for (int i = 0; i < words.length; i++) {
            s2idx.put(words[i], i);
        }
        for (String word : s2idx.keySet()) {
            int idx = s2idx.get(word);
            TrieNode cur = frontRoot;
            for (int i = 0; i < word.length(); i++) {
                if (cur.children[word.charAt(i) - 'a'] == null) {
                    cur.children[word.charAt(i) - 'a'] = new TrieNode();
                }
                cur = cur.children[word.charAt(i) - 'a'];
                cur.set.add(idx);
            }

            cur = backRoot;
            for (int i = word.length() - 1; i >= 0; i--) {
                if (cur.children[word.charAt(i) - 'a'] == null) {
                    cur.children[word.charAt(i) - 'a'] = new TrieNode();
                }
                cur = cur.children[word.charAt(i) - 'a'];
                cur.set.add(idx);
            }
        }
    }

    public int f(String pref, String suff) {
        TrieNode cur = frontRoot;
        for (int i = 0; i < pref.length(); i++) {
            if (cur.children[pref.charAt(i) - 'a'] == null) {
                return -1;
            }
            cur = cur.children[pref.charAt(i) - 'a'];
        }
        Set<Integer> candidates = cur.set;

        cur = backRoot;
        for (int i = suff.length() - 1; i >= 0; i--) {
            if (cur.children[suff.charAt(i) - 'a'] == null) {
                return -1;
            }
            cur = cur.children[suff.charAt(i) - 'a'];
        }
        int res = -1;
        for (Integer e : cur.set) {
            if (candidates.contains(e) && e > res) {
                res = e;
            }
        }
        return res;
    }
}

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter obj = new WordFilter(words);
 * int param_1 = obj.f(pref,suff);
 */
