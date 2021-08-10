#include <stdlib.h>
#include <string.h>

char*
addStrings(char* num1, char* num2)
{
  int len1 = strlen(num1), len2 = strlen(num2);
  char buff[10002] = { 0 };
  int a, b, carry = 0, tp = 0;
  for (int i = len1 - 1, j = len2 - 1; i >= 0 || j >= 0; i--, j--) {
    a = i >= 0 ? num1[i] - '0' : 0;
    b = j >= 0 ? num2[j] - '0' : 0;
    carry += a + b;
    buff[tp++] = carry % 10 + '0';
    carry /= 10;
  }
  if (carry)
    buff[tp++] = carry + '0';
  for (int i = 0, j = tp - 1; i < j; i++, j--) {
    char tc = buff[i];
    buff[i] = buff[j];
    buff[j] = tc;
  }
  char* res = (char*)malloc(sizeof(buff));
  strcpy(res, buff);
  return res;
}
