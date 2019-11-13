class Solution {
public:
    int mySqrt_MK1(int x);
    int mySqrt_MK2(int x);
};

// Binary search. 二分查找法.
int Solution::mySqrt_MK1(int x) 
{
    if (x <= 1)
        return x;

    int left = 1, right = x / 2;
    while (left <= right) {
        int mid = left + ((right - left) >> 1);
        if (mid == x / mid)
            return mid;
        else if (mid > x / mid)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return right;
}

// Newton method. 牛顿法
int Solution::mySqrt_MK2(int x)
{
    if (x == 0)
        return x;

    int t = x / 2 + 1;  // if x > 1, sqrt(x) <= x / 2 + 1
    while (t > x / t) 
        t = (t + x / t) / 2;
    return t;
}
