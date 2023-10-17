class Solution {
public:
    int sumOfMultiples(int n)
    {
        return s(3, n / 3) + s(5, n / 5) + s(7, n / 7) - s(15, n / 15) - s(21, n / 21) - s(35, n / 35) + s(105, n / 105);
    }

private:
    int s(int d, int n)
    {
        return n * d + d * n * (n - 1) / 2;
    }
};
