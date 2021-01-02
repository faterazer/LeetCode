#include <stdbool.h>

bool canFormArray(int *arr, int arrSize, int **pieces, int piecesSize, int *piecesColSize)
{
    int hash[101] = {0};
    for (int i = 0; i < piecesSize; i++)
        hash[pieces[i][0]] = i + 1;
    for (int i = 0; i < arrSize;) {
        if (!hash[arr[i]])
            return false;
        int idx = hash[arr[i]] - 1;
        for (int j = 0; j < piecesColSize[idx]; j++)
            if (arr[i++] != pieces[idx][j])
                return false;
    }
    return true;
}
