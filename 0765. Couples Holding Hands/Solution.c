void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int get_partner(int x)
{
    return x ^ 1;
}

int minSwapsCouples(int* row, int rowSize)
{
    int pos[rowSize];
    for (int i = 0; i < rowSize; i++)
        pos[row[i]] = i;

    int res = 0;
    for (int i = 0; i < rowSize; i += 2) {
        int partner = get_partner(row[i]);
        while (row[i + 1] != partner) {
            int partner2 = get_partner(row[i + 1]);
            int pos2 = pos[partner2] ^ 1;
            swap(pos, row[i + 1], partner2);
            swap(row, i + 1, pos2);
            ++res;
        }
    }
    return res;
}
