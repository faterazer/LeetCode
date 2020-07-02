class Solution {
    public int findComplement_MK1(int num) {
        int mask = ~0;
        while ((num & mask) != 0)
            mask <<= 1;
        return num ^ ~mask;
    }

    public int findComplement_MK2(int num) {
        int mask = 1;
        while (mask < num)
            mask = mask << 1 | 1;
        return num ^ mask;
    }

    public int findComplement_MK3(int num) {
        return ~num & (Integer.highestOneBit(num) - 1);
    }
}
