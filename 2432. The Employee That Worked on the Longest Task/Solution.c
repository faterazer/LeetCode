int hardestWorker(int n, int** logs, int logsSize, int* logsColSize)
{
    int res = logs[0][0], max = logs[0][1];
    for (int i = 1; i < logsSize; i++) {
        int span = logs[i][1] - logs[i - 1][1];
        if (span > max || (span == max && logs[i][0] < res)) {
            max = span;
            res = logs[i][0];
        }
    }
    return res;
}
