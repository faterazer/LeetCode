class Solution
{
public:
    int addDigits(int num);
};

int Solution::addDigits(int num)
{
    return 1 + (num - 1) % 9;
}
