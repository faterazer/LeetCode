class Solution {
public:
    int differenceOfSums(int n, int m)
    {
        return n * (n + 1) / 2 - m * (n / m) * (1 + n / m);
    }
};
