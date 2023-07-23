bool knows(int a, int b);

/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n)
    {
        int res = 0;
        for (int i = 1; i < n; i++)
            if (knows(res, i))
                res = i;
        for (int i = 0; i < n; i++) {
            if (i == res)
                continue;
            if (knows(res, i) || !knows(i, res))
                return -1;
        }
        return res;
    }
};
