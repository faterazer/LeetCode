#include <stdbool.h>

bool canPlaceFlowers(int *flowerbed, int flowerbedSize, int n)
{
    for (int i = 0; i < flowerbedSize; i++) {
        if (!flowerbed[i] && (i - 1 < 0 || !flowerbed[i - 1]) && (i + 1 >= flowerbedSize || !flowerbed[ i + 1])) {
            n--;
            flowerbed[i] = 1;
        }
        if (n <= 0)
            return true;
    }
    return false;
}
