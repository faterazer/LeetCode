class Solution {
    public char nextGreatestLetter(char[] letters, char target) {
        int low = 0, high = letters.length - 1, mid;
        while (low <= high) {
            mid = low + ((high - low) >> 1);
            if (letters[mid] <= target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return letters[low % letters.length];
    }
}
