char kthCharacter(int k)
{
    return 'a' + __builtin_popcount(k - 1);
}
