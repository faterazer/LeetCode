int maximumUnits(int **boxTypes, int boxTypesSize, int *boxTypesColSize, int truckSize)
{
    int buckets[1001] = {0}, res = 0;
    for (int i = 0; i < boxTypesSize; i++)
        buckets[boxTypes[i][1]] += boxTypes[i][0];
    for (int i = 1000; i > 0; i--) {
        if (buckets[i] < truckSize) {
            res += buckets[i] * i;
            truckSize -= buckets[i];
        } else {
            res += truckSize * i;
            break;
        }
    }
    return res;
}
