int findComplement_MK1(int num)
{
    unsigned mask = 0;
    for (int n = num; n; n >>= 1)
        mask = mask << 1 | 1;
    return ~num & mask;
}

int findComplement_MK2(int num)
{
    unsigned mask = 1;
    while (mask < num)
        mask = mask << 1 | 1;
    return num ^ mask;
}

int findComplement_MK3(int num)
{
    unsigned mask = ~0;
    while (num & mask)
        mask <<= 1;
    return num ^ ~mask;
}
