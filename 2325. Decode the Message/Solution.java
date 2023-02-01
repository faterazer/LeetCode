import java.util.HashMap;
import java.util.Map;

class Solution {
    public String decodeMessage(String key, String message) {
        char cur = 'a';
        Map<Character, Character> mapping = new HashMap<>();

        for (int i = 0; i < key.length(); i++) {
            char c = key.charAt(i);
            if (c != ' ' && !mapping.containsKey(c)) {
                mapping.put(c, cur++);
            }
        }

        char[] msg = message.toCharArray();
        for (int i = 0; i < msg.length; i++) {
            if (msg[i] != ' ') {
                msg[i] = mapping.get(msg[i]);
            }
        }
        return new String(msg);
    }
}
