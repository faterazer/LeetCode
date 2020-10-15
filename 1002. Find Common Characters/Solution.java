import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
    public List<String> commonChars(String[] A) {
        int[] hash = new int[26];
        Arrays.fill(hash, Integer.MAX_VALUE);
        int[] hashBuff = new int[26];
        for (String s : A) {
            Arrays.fill(hashBuff, 0);
            for (char ch : s.toCharArray())
                hashBuff[ch - 'a']++;
            for (int i = 0; i < 26; i++)
                hash[i] = Math.min(hash[i], hashBuff[i]);
        }
        List<String> ret = new ArrayList<>();
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < hash[i];j++)
                ret.add(String.valueOf((char)('a' + i)));
        }
        return ret;
    }
}
