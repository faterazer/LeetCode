class Solution {
    public int minNumberOfFrogs(String croakOfFrogs) {
        int[] counter = new int[5];
        int res = 0, frogs = 0;
        String croak = "croak";
        for (int i = 0; i < croakOfFrogs.length(); i++) {
            int idx = croak.indexOf(croakOfFrogs.charAt(i));
            ++counter[idx];
            if (idx == 0) {
                res = Math.max(res, ++frogs);
            } else if (--counter[idx - 1] < 0) {
                return -1;
            } else if (idx == 4) {
                --frogs;
            }
        }
        return frogs == 0 ? res : -1;
    }
}
