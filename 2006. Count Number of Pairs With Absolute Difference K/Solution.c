int countKDifference(int* nums, int numsSize, int k)
{
    int map[101] = { 0 };
    int res = 0, tmp;
    for (int i = 0; i < numsSize; i++) {
        tmp = nums[i] - k;
        if (tmp > 0 && map[tmp])
            res += map[tmp];
        tmp = nums[i] + k;
        if (tmp <= 100 && map[tmp])
            res += map[tmp];
        map[nums[i]]++;
    }
    return res;
}
