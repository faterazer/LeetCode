class Solution {
    public boolean backspaceCompare(String S, String T) {
        int skipS = 0, skipT = 0;
        for (int i = S.length() - 1, j = T.length() - 1; i >= 0 || j >= 0; i--, j--) {
            for (; i >= 0 && (S.charAt(i) == '#' || skipS != 0); i--) {
                if (S.charAt(i) == '#')
                    skipS++;
                else
                    skipS--;
            }
            for (; j >= 0 && (T.charAt(j) == '#' || skipT != 0); j--) {
                if (T.charAt(j) == '#')
                    skipT++;
                else
                    skipT--;
            }
            if ((i >= 0) != (j >= 0) || (i >= 0 && j >= 0 && S.charAt(i) != T.charAt(j)))
                return false;
        }
        return true;
    }
}
