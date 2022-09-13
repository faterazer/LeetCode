class Solution {
    public int maximumSwap(int num) {
        char[] chars = Integer.toString(num).toCharArray();
        int[] maxIndex = new int[10];
        for (int i = 0; i < chars.length; i++) {
            maxIndex[chars[i] - '0'] = i;
        }
        for (int i = 0; i < chars.length; i++) {
            int x = chars[i] - '0';
            for (int j = 9; j > x; j--) {
                if (maxIndex[j] > i) {
                    char temp = chars[i];
                    chars[i] = chars[maxIndex[j]];
                    chars[maxIndex[j]] = temp;
                    return Integer.parseInt(new String(chars));
                }
            }
        }
        return Integer.parseInt(new String(chars));
    }
}
