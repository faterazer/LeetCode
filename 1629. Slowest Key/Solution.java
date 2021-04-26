class Solution {
    public char slowestKey(int[] releaseTimes, String keysPressed) {
        char res = keysPressed.charAt(0);
        int max_duration = releaseTimes[0], duration;
        for (int i = 1; i < releaseTimes.length; i++) {
            duration = releaseTimes[i] - releaseTimes[i - 1];
            if (duration > max_duration) {
                max_duration = duration;
                res = keysPressed.charAt(i);
            } else if (duration == max_duration && keysPressed.charAt(i) > res) {
                res = keysPressed.charAt(i);
            }
        }
        return res;
    }
}
