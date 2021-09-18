class Solution
{
public:
    bool canWinNim(int n);
};

bool Solution::canWinNim(int n)
{
    return n % 4 != 0;
}
