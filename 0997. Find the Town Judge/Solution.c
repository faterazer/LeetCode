#include <memory.h>
#include <stdlib.h>

int findJudge(int N, int **trust, int trustSize, int *trustColSize)
{
    int *buff = (int*)malloc(sizeof(int) * (N + 1));
    memset(buff, 0, sizeof(int) * (N + 1));
    for (int i = 0; i < trustSize; i++) {
        buff[trust[i][0]]--;
        buff[trust[i][1]]++;
    }
    for (int i = 1; i <= N; i++)
        if (buff[i] == N - 1)
            return i;
    return -1;
}
