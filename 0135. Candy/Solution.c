int candy(int* ratings, int ratingsSize)
{
    int inc = 1, dec = 0, pre = 1, res = 1;
    for (int i = 1; i < ratingsSize; ++i) {
        if (ratings[i] >= ratings[i - 1]) {
            dec = 0;
            pre = ratings[i] == ratings[i - 1] ? 1 : pre + 1;
            res += pre;
            inc = pre;
        } else if (ratings[i] < ratings[i - 1]) {
            ++dec;
            if (dec == inc)
                ++dec;
            res += dec;
            pre = 1;
        }
    }
    return res;
}
