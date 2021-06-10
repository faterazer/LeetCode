#include <ctype.h>
#include <stddef.h>
#include <stdlib.h>

char* sortSentence(char *s)
{
	char *arr[9] = {NULL};
	int i, j;
	for (i = j = 0; s[j]; j++) {
		if (isdigit(s[j])) {
			arr[s[j] - '1'] = s + i;
			i = j + 2;
		}
	}
	char *res = (char*)malloc(sizeof(char) * j);
	int len = 0;
	for (i = 0; i < 9 && arr[i]; i++) {
		for (j = 0; !isdigit(arr[i][j]); j++)
			res[len++] = arr[i][j];
		res[len++] = ' ';
	}
	res[len - 1] = '\0';
	return res;
}
