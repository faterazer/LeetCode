class Solution {
public:
    int passThePillow(int n, int time)
    {
        int div = time / (n - 1), mod = time % (n - 1);
        return (div & 1) ? n - mod : 1 + mod;
    }
};
