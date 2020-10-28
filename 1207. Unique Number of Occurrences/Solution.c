bool uniqueOccurrences(int *arr, int arrSize)
{
    int map[2001] = {0};
    int set[1001] = {0};
    for (int i = 0; i < arrSize; i++)
        map[arr[i] + 1000]++;
    for (int i = 0; i < 2001; i++) {
        if (!map[i])
            continue;
        if (set[map[i]])
            return false;
        set[map[i]] = 1;
    }
    return true;
}
