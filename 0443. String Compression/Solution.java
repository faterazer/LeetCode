class Solution {
    public int compress(char[] chars) {
        int i = 0, idx = 0;
        while (i < chars.length) {
            char ch = chars[i];
            int count = 0;
            while (i < chars.length && chars[i] == ch) {
                ++count;
                ++i;
            }

            chars[idx++] = ch;
            if (count > 1) {
                int j = idx;
                while (count != 0) {
                    chars[idx++] = (char) (count % 10 + '0');
                    count /= 10;
                }
                reverse(chars, j, idx - 1);
            }
        }
        return idx;
    }

    private void reverse(char[] chars, int left, int right) {
        char temp;
        while (left <= right) {
            temp = chars[left];
            chars[left++] = chars[right];
            chars[right--] = temp;
        }
    }
}
