#include <stdlib.h>
#include <string.h>

const int values[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
const char* symbols[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };

char* intToRoman(int num)
{
    char* res = (char*)calloc(20, sizeof(char));
    for (int i = 0; i < 13; i++) {
        while (num >= values[i]) {
            num -= values[i];
            strcat(res, symbols[i]);
        }
    }
    return res;
}
