#define max(a, b) ((a > b) ? (a) : (b))
#define min(a, b) ((a < b) ? (a) : (b))

double findMaxAverage(int* nums, int numsSize, int k){
    int sum = 0;
    for (int i = 0; i < k; i++)
        sum += nums[i];
    int maxSum = sum;
    for (int i = k; i < numsSize; i++) {
        sum += nums[i] - nums[i - k];
        maxSum = max(maxSum, sum);
    }
    return (double)maxSum / k;
}
