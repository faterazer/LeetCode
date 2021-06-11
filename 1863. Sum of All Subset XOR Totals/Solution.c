int subsetXORSum(int *nums, int numsSize)
{
	int res = 0;
	for (int i = 0; i < numsSize; i++)
		res |= nums[i];
	return res << (numsSize - 1);
}
