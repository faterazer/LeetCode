class Solution {
    public String maximumTime(String time) {
        char[] res = time.toCharArray();
        if (res[0] == '?')
            res[0] = res[1] == '?' || res[1]  < '4' ? '2' : '1';
        if (res[1] == '?')
            res[1] = res[0] == '2' ? '3' : '9';
        if (res[3] == '?')
            res[3] = '5';
        if (res[4] == '?')
            res[4] = '9';
        return new String(res);
    }
}
