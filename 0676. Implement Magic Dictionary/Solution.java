class Trie {
    boolean isEnd = false;
    Trie[] children = new Trie[26];

    Trie() {
    }
}

class MagicDictionary {


    private final Trie root = new Trie();

    public MagicDictionary() {

    }

    private boolean dfs(Trie root, String word, int idx, int limit) {
        if (idx == word.length()) {
            return root.isEnd && limit == 0;
        }
        int i = word.charAt(idx) - 'a';
        if (root.children[i] != null && dfs(root.children[i], word, idx + 1, limit)) {
            return true;
        }
        if (limit > 0) {
            for (int j = 0; j < 26; j++) {
                if (i != j && root.children[j] != null && dfs(root.children[j], word, idx + 1, limit - 1)) {
                    return true;
                }
            }
        }
        return false;
    }

    public void buildDict(String[] dictionary) {
        for (String word : dictionary) {
            Trie cur = root;
            for (int i = 0; i < word.length(); i++) {
                int idx = word.charAt(i) - 'a';
                if (cur.children[idx] == null) {
                    cur.children[idx] = new Trie();
                }
                cur = cur.children[idx];
            }
            cur.isEnd = true;
        }
    }

    public boolean search(String searchWord) {
        return dfs(root, searchWord, 0, 1);
    }
}

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dictionary);
 * boolean param_2 = obj.search(searchWord);
 */
