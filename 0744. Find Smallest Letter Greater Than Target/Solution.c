char nextGreatestLetter(char *letters, int lettersSize, char target)
{
    int low = 0, high = lettersSize - 1, mid;
    while (low <= high) {
        mid = low + ((high - low) >> 1);
        if (letters[mid] <= target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return letters[low % lettersSize];
}
