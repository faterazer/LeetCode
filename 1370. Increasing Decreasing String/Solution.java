class Solution {
    public String sortString(String s) {
        int[] map = new int[26];
        for (char c : s.toCharArray())
            map[c - 'a']++;

        StringBuilder res = new StringBuilder();
        while (res.length() != s.length()) {
            for (int i = 0; i < 26; i++)
                if (map[i]-- > 0)
                    res.append((char)('a' + i));
            for (int i = 25; i >= 0; i--)
                if (map[i]-- > 0)
                    res.append((char)('a' + i));
        }
        return res.toString();
    }
}
