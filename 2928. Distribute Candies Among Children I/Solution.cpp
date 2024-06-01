class Solution {
public:
    int distributeCandies(int n, int limit)
    {
        return comb2(n + 2) - 3 * comb2(n - limit + 1) + 3 * comb2(n - 2 * limit) - comb2(n - 3 * limit - 1);
    }

private:
    int comb2(int x)
    {
        return x > 1 ? x * (x - 1) / 2 : 0;
    }
};