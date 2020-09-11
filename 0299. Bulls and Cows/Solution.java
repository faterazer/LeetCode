class Solution {
    public String getHint(String secret, String guess) {
        int[] map = new int[10];
        int A = 0, B = 0;
        for (int i = 0; i < secret.length(); i++) {
            if (secret.charAt(i) == guess.charAt(i)) {
                A++;
            } else {
                if (map[secret.charAt(i) - '0']++ < 0)
                    B++;
                if (map[guess.charAt(i) - '0']-- > 0)
                    B++;
            }
        }
        return A + "A" + B + "B";
    }
}
