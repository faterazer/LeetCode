class Solution {
public:
    bool isHappy(int n);
private:
    int digitSquareSum(int n);
};

bool Solution::isHappy(int n)
{
    int slow = n, fast = n;
    do {
        slow = digitSquareSum(slow);
        fast = digitSquareSum(fast);
        fast = digitSquareSum(fast);
        if (fast == 1)
            return true;
    } while (slow != fast);
    return false;
}

int Solution::digitSquareSum(int n)
{
    int sum = 0;
    while (n) {
        sum += (n % 10) * (n % 10);
        n /= 10;
    }
    return sum;
}
