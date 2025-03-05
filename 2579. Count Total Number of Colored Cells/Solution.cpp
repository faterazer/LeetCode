class Solution {
public:
    long long coloredCells(long long n)
    {
        return 2 * n * (n - 1) + 1;
    }
};
