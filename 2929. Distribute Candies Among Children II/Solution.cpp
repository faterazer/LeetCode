class Solution {
public:
    long long distributeCandies(int n, int limit)
    {
        return C2(n + 2) - 3 * C2(n - limit + 1) + 3 * C2(n - 2 * limit) - C2(n - 3 * limit - 1);
    }

private:
    long long C2(long long n)
    {
        return n > 1 ? n * (n - 1) / 2 : 0;
    }
};
