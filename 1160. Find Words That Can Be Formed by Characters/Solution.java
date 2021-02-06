class Solution {
    public int countCharacters(String[] words, String chars) {
        int res = 0;
        int[] table = new int[26];
        for (char ch : chars.toCharArray()) {
            table[ch - 'a']++;
        }
        for (String word : words) {
            res += word.length();
            int[] tempTable = new int[26];
            for (char ch : word.toCharArray()) {
                if (++tempTable[ch - 'a'] > table[ch - 'a']) {
                    res -= word.length();
                    break;
                }
            }
        }
        return res;
    }
}
