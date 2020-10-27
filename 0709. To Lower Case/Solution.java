class Solution {
    public String toLowerCase(String str) {
        char[] s = str.toCharArray();
        for (int i = 0; i < s.length; i++)
            if (s[i] >= 'A' && s[i] <= 'Z')
                s[i] = (char)('a' + s[i] - 'A');
        return new String(s);
    }
}
