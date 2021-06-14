class Solution {
    public boolean isSumEqual(String firstWord, String secondWord, String targetWord) {
        return wordToNumber(firstWord) + wordToNumber(secondWord) == wordToNumber(targetWord);
    }

    private int wordToNumber(String word) {
        int res = 0;
        for (int i = 0; i < word.length(); i++) {
            res = res * 10 + word.charAt(i) - 'a';
        }
        return res;
    }
}
