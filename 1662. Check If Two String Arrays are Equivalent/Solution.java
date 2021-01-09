class Solution {
    public boolean arrayStringsAreEqual(String[] word1, String[] word2) {
        return String.join("", word1).compareTo(String.join("", word2)) == 0;
    }
}
