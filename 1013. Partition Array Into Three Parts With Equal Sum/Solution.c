#include <stdbool.h>

bool canThreePartsEqualSum(int *arr, int arrSize)
{
    int total = 0;
    for (int i = 0; i < arrSize; i++)
        total += arr[i];
    if (total % 3)
        return false;
    int sum = 0, target = total / 3, cnt = 0;
    int limit = target == 0 ? 3 : 2;
    for (int i = 0; i < arrSize && cnt < limit; i++) {
        sum += arr[i];
        if (sum == target) {
            sum = 0;
            cnt++;
        }
    }
    return cnt == limit;
}
