class Solution {
    public int countValidWords(String sentence) {
        String pattern = "([a-z]+-[a-z]+|[a-z]*)[!\\\\.,]?";
        int res = 0;
        for (String word : sentence.trim().split("\\s+")) {
            if (word.matches(pattern)) {
                res++;
            }
        }
        return res;
    }
}
