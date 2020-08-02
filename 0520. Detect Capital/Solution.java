class Solution {
    public boolean detectCapitalUse_MK1(String word) {
        int uc = 0;
        for (int i = 0; i < word.length(); i++) {
            if (Character.isUpperCase(word.charAt(i)) && uc++ < i)
                return false;
        }
        return uc == word.length() || uc <= 1;
    }

    public boolean detectCapitalUse_MK2(String word) {
        return word.matches("[A-Z]*|.[a-z]*");
    }
}
