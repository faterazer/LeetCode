int numberOfSteps(int num)
{
    int res = 0;
    while (num) {
        if (num & 1)
            num -= 1;
        else
            num >>= 1;
        res++;
    }
    return res;
}
