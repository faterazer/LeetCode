/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* finalPrices(int *prices, int pricesSize, int *returnSize)
{
    int stack[500], len = 0;
    *returnSize = pricesSize;
    for (int i = 0; i < pricesSize; i++) {
        while (len && prices[stack[len - 1]] >= prices[i])
            prices[stack[--len]] -= prices[i];
        stack[len++] = i;
    }
    return prices;
}
