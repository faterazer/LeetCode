int sumSubarrayMins(int* arr, int arrSize)
{
    int stack[arrSize], tp = 0;
    int dp[arrSize];
    int res = 0, P = 1e9 + 7;
    for (int i = 0; i < arrSize; i++) {
        while (tp && arr[stack[tp - 1]] > arr[i])
            --tp;
        int j = tp ? stack[tp - 1] : -1;
        dp[i] = (i - j) * arr[i] + (j >= 0 ? dp[j] : 0);
        res = (res + dp[i]) % P;
        stack[tp++] = i;
    }
    return res;
}
