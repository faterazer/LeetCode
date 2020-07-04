import java.util.ArrayList;
import java.util.List;

class Solution {
    public String[] findWords(String[] words) {
        int[] mp = {1, 2, 2, 1, 0, 1, 1, 1, 0, 1, 1, 1, 2, 2, 0, 0, 0, 0, 1, 0, 0, 2, 0, 2, 0, 2};
        List<String> ret = new ArrayList<String>();
        for (String word : words) {
            ret.add(word);
            for (int i = 1; i < word.length(); i++)
                if (mp[word.toLowerCase().charAt(i) - 'a'] != mp[word.toLowerCase().charAt(0) - 'a']) {
                    ret.remove(ret.size() - 1);
                    break;
                }
        }
        return ret.toArray(new String[0]);
    }
}
