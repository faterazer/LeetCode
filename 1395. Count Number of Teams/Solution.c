#include <math.h>
#include <string.h>

void updateBIT(int* BIT, int BIT_size, int idx, int val)
{
    while (idx < BIT_size) {
        BIT[idx] += val;
        idx += idx & (-idx);
    }
}

int getPrefixSum(int* BIT, int idx)
{
    int res = 0;
    while (idx > 0) {
        res += BIT[idx];
        idx -= idx & (-idx);
    }
    return res;
}

int numTeams(int* rating, int ratingSize)
{
    int max_rating = 0;
    for (int i = 0; i < ratingSize; i++)
        max_rating = fmax(max_rating, rating[i]);

    int BIT_size = max_rating + 1;
    int left_BIT[BIT_size], right_BIT[BIT_size];
    memset(left_BIT, 0, sizeof(left_BIT));
    memset(right_BIT, 0, sizeof(right_BIT));

    for (int i = 0; i < ratingSize; i++)
        updateBIT(right_BIT, BIT_size, rating[i], 1);

    int res = 0;
    for (int i = 0; i < ratingSize; i++) {
        updateBIT(right_BIT, BIT_size, rating[i], -1);
        int left_less = getPrefixSum(left_BIT, rating[i] - 1);
        int left_more = getPrefixSum(left_BIT, max_rating) - getPrefixSum(left_BIT, rating[i]);
        int right_less = getPrefixSum(right_BIT, rating[i] - 1);
        int right_more = getPrefixSum(right_BIT, max_rating) - getPrefixSum(right_BIT, rating[i]);
        updateBIT(left_BIT, BIT_size, rating[i], 1);

        res += left_less * right_more + left_more * right_less;
    }
    return res;
}
