class Solution {
    public boolean checkRecord_MK1(String s) {
        int absent = 0, contin_late = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == 'L')
                contin_late++;
            else {
                contin_late = 0;
                if (s.charAt(i) == 'A')
                    absent++;
            }
            if (absent > 1 || contin_late > 2)
                return false;
        }
        return true;
    }

    public boolean checkRecord_MK2(String s) {
        return s.indexOf('A') == s.lastIndexOf('A') && s.indexOf("LLL") == -1;
    }

    public boolean checkRecord_MK3(String s) {
        return !s.matches(".*(A.*A|LLL).*");
    }
}
