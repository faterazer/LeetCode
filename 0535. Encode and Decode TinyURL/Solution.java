import java.util.*;

public class Codec {
    private final List<Character> candidates = new ArrayList<>();
    private final Map<String, String> code2url = new HashMap<>();
    Random random = new Random();

    Codec() {
        for (int i = 0; i < 26; i++) {
            if (i < 10) {
                candidates.add((char) ('0' + i));
            }
            candidates.add((char) ('a' + i));
            candidates.add((char) ('A' + i));
        }
    }

    // Encodes a URL to a shortened URL.
    public String encode(String longUrl) {
        StringBuilder key = new StringBuilder();
        do {
            int idx = random.nextInt(candidates.size());
            key.append(candidates.get(idx));
        } while (code2url.containsKey(key.toString()));
        code2url.put(key.toString(), longUrl);
        return "http://tinyurl.com/" + key;
    }

    // Decodes a shortened URL to its original URL.
    public String decode(String shortUrl) {
        int idx = shortUrl.lastIndexOf('/') + 1;
        String key = shortUrl.substring(idx);
        return code2url.get(key);
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.decode(codec.encode(url));
