class Solution {
    public boolean areSentencesSimilar(String sentence1, String sentence2) {
        String[] words1 = sentence1.split(" ");
        String[] words2 = sentence2.split(" ");
        if (words1.length < words2.length) {
            String[] temp = words1;
            words1 = words2;
            words2 = temp;
        }
        int i = 0;
        while (i < words2.length && words1[i].equals(words2[i])) {
            ++i;
        }
        int k = words1.length, j = words2.length;
        while (j > i && words1[k - 1].equals(words2[j - 1])) {
            --k;
            --j;
        }
        return i == j;
    }
}
