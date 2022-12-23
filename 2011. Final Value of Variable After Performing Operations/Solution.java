class Solution {
    public int finalValueAfterOperations(String[] operations) {
        int x = 0;
        for (String operation : operations) {
            if (operation.charAt(1) == '+') {
                ++x;
            } else {
                --x;
            }
        }
        return x;
    }
}
