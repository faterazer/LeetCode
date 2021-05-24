class Solution {
    public String mergeAlternately(String word1, String word2) {
        StringBuilder sb = new StringBuilder();
        int i = 0, j = 0;
        for (; i < word1.length() && j < word2.length(); i++, j++) {
            sb.append(word1.charAt(i)).append(word2.charAt(j));
        }
        if (i == word1.length()) {
            sb.append(word2.substring(j));
        } else {
            sb.append(word1.substring(i));
        }
        return sb.toString();
    }
}
