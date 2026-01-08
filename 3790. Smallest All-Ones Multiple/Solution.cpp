class Solution {
public:
    int minAllOneMultiple(int k)
    {
        if (k % 2 == 0 || k % 5 == 0)
            return -1;
        int x = 1;
        for (int i = 1; i <= k; ++i) {
            if (x == 0)
                return i;
            x = (x * 10 + 1) % k;
        }
        return -1;
    }
};
