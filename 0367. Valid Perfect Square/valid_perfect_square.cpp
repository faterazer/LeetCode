class Solution
{
public:
    bool isPerfectSquare(int num);
private:
    int sqrtByLinearSearch(int n);
    int sqrtByBinarySearch(int n);
    int sqrtByNewton(int n);
};

bool Solution::isPerfectSquare(int num)
{
    int root = sqrtByNewton(num);
    return num % root == 0 && num / root == root;
}

int Solution::sqrtByLinearSearch(int n)
{
    int i = 1;
    while (i <= n / i)
        i++;
    return i - 1;
}

int Solution::sqrtByBinarySearch(int n)
{
    if (n == 1)
        return n;
    
    int left = 2, right = n / 2, mid;
    while (left <= right) {
        mid = left + ((right - left) >> 1);
        if (mid < n / mid)
            left = mid + 1;
        else if (mid > n / mid)
            right = mid - 1;
        else
            return mid;
    }
    return right;
}

int Solution::sqrtByNewton(int n)
{
    int r = n / 2;
    while (r > n / r)
        r = (r + n / r) / 2;
    return r;
}
