import java.util.stream.IntStream;

class Solution {
    public int maxNumberOfBalloons(String text) {
        int[] count = new int[26];
        for (char ch : text.toCharArray()) {
            count[ch - 'a']++;
        }
        return IntStream.of(count[0], count[1], count[11] / 2, count[14] / 2, count[13]).min().getAsInt();
    }
}
