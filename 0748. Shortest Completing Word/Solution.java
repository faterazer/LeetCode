import java.util.Arrays;

class Solution {
    public String shortestCompletingWord(String licensePlate, String[] words) {
        int[] hash = new int[26];
        for (int i = 0; i < licensePlate.length(); i++)
            if (Character.isLetter(licensePlate.charAt(i)))
                hash[Character.toLowerCase(licensePlate.charAt(i)) - 'a']++;
        String ans = "aaaaaaaaaaaaaaaa";
        int[] counter = new int[26];
        for (String word : words) {
            if (word.length() >= ans.length())
                continue;
            Arrays.fill(counter, 0);
            for (int i = 0; i < word.length(); i++)
                counter[word.charAt(i) - 'a']++;
            int j = 0;
            while (j < 26 && counter[j] >= hash[j])
                j++;
            if (j == 26)
                ans = word;
        }
        return ans;
    }
}
