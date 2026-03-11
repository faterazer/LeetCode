class Solution {
public:
    // 递归法
    char findKthBit_MK1(int n, int k) {
        if (n == 1)
            return '0';
        if (k == 1 << (n - 1))
            return '1';
        else if (k < (1 << (n - 1)))
            return findKthBit_MK1(n - 1, k);
        else
            return findKthBit_MK2(n - 1, (1 << n) - k) ^ 1;
    }

    // 数学法
    char findKthBit_MK2(int n, int k) {
        if (k & 1)
            return '0' + k / 2 % 2;
        k /= k & -k;
        return '1' - k / 2 % 2;
    }
};
