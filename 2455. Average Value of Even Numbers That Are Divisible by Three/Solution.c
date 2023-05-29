int averageValue(int* nums, int numsSize)
{
    int sum = 0, cnt = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] % 6 == 0) {
            sum += nums[i];
            cnt++;
        }
    }
    return cnt ? sum / cnt : 0;
}
