import java.util.*;

class Node {
    public String word;
    public int index;

    Node(String w, int i) {
        word = w;
        index = i;
    }
}

class Solution {
    private Map<String, Integer> counter(String[] words) {
        Map<String, Integer> res = new HashMap<>();
        for (String word : words) {
            res.put(word, res.getOrDefault(word, 0) + 1);
        }
        return res;
    }

    private boolean isSubsequence(String s, String t) {
        int si = 0, ti = 0;
        while (si < s.length() && ti < t.length()) {
            if (s.charAt(si) == t.charAt(ti)) {
                ++ti;
            }
            ++si;
        }
        return ti == t.length();
    }

    public int numMatchingSubseq_MK1(String s, String[] words) {
        Map<String, Integer> wordCounter = counter(words);
        int res = 0;
        for (String word : wordCounter.keySet()) {
            if (isSubsequence(s, word)) {
                res += wordCounter.get(word);
            }
        }
        return res;
    }

    public int numMatchingSubseq_MK2(String s, String[] words) {
        int[][] dp = new int[s.length() + 1][26];
        Arrays.fill(dp[dp.length - 1], -1);
        for (int i = dp.length - 2; i >= 0; i--) {
            dp[i] = dp[i + 1].clone();
            dp[i][s.charAt(i) - 'a'] = i + 1;
        }

        int res = 0;
        Map<String, Integer> wordCounter = counter(words);
        for (String word : wordCounter.keySet()) {
            int index = 0;
            for (int i = 0; i < word.length() && index != -1; i++) {
                index = dp[index][word.charAt(i) - 'a'];
            }
            if (index != -1) {
                res += wordCounter.get(word);
            }
        }
        return res;
    }

    public int numMatchingSubseq_MK3(String s, String[] words) {
        List<Deque<Node>> buckets = new ArrayList<>(26);
        for (int i = 0; i < 26; i++) {
            buckets.add(new ArrayDeque<>());
        }
        Map<String, Integer> wordCounter = counter(words);
        for (String word : wordCounter.keySet()) {
            buckets.get(word.charAt(0) - 'a').addLast(new Node(word, 0));
        }

        int res = 0;
        for (int i = 0; i < s.length(); i++) {
            Deque<Node> bucket = buckets.get(s.charAt(i) - 'a');
            int size = bucket.size();
            for (int j = 0; j < size; j++) {
                Node node = bucket.removeFirst();
                ++node.index;
                if (node.index == node.word.length()) {
                    res += wordCounter.get(node.word);
                } else {
                    buckets.get(node.word.charAt(node.index) - 'a').addLast(node);
                }
            }
        }
        return res;
    }
}
