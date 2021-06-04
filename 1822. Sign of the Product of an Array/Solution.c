int arraySign(int *nums, int numsSize)
{
    int res = 1;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < 0) {
            res *= -1;
        } else if (!nums[i]) {
            return 0;
        }
    }
    return res;
}
