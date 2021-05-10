class Solution {
    public String reformatNumber(String number) {
        StringBuilder sb = new StringBuilder();
        int count = 0;
        for (int i = 0; i < number.length(); i++) {
            if (!Character.isDigit(number.charAt(i)))
                continue;
            count++;
            if ((sb.length() + 1) % 4 == 0) {
                sb.append('-');
            }
            sb.append(number.charAt(i));
        }
        if (count > 1 && count % 3 == 1) {
            sb.setCharAt(sb.length() - 2, sb.charAt(sb.length() - 3));
            sb.setCharAt(sb.length() - 3, '-');
        }
        return sb.toString();
    }
}
