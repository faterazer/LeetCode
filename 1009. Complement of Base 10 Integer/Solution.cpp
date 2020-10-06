class Solution
{
public:
    int bitwiseComplement_MK1(int N)
    {
        unsigned mask = 1;
        while (mask < N)
            mask = mask << 1 | 1;
        return N ^ mask;
    }

    int bitwiseComplement_MK2(int N) 
    {
        unsigned mask = ~0U << 1;
        while (mask & N)
            mask <<= 1;
        return N ^ ~mask;
    }
};
